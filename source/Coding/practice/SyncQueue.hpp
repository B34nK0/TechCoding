/*
同步队列
用于接收线程池待处理任务，采用条件变量实现线程通信，当队列为空时等待，不为空时通知线程去处理。

*/
#include<list>
#include<mutex>
#include<condition_variable>

using namespace std;

template<typename T>
class SyncQueue {
private:
	list<T> _queue;			//采用链表缓存任务
	int _maxSize;	//控制任务缓存区
	bool _needStop;	//生命周期
	mutex _mutex;	//缓冲区锁
	condition_variable _notEmpty;	//链表不为空时通知
	condition_variable _notFull;	//没有满时通知


public:

	SyncQueue(int size) : _maxSize(size), _needStop(false) {

	}

	void Put(const T& x) {
		Add(x);
	}

	void Put(T&& x) {
		Add(forward<T>(x));
	}

	//当有空闲线程时，获取任务，不局限于一个个拿，可以批量拿任务进行处理
	//当时批量拿的话也有问题在于如果拿到大部分耗时任务，那么会导致某个线程突然很忙碌而其他线程却空闲
	//也可以通过任务窃取的方式，让空闲的线程去窃取忙碌线程的任务，需要采用全局任务队列进行维护
	void Take(list<T>& list) {
		unique_lock<mutex> locker(_mutex);
		//当处于waiting状态的线程被notify_one 或 notify_all时，获取到mutex，然后判断调整是否满足，如果满足则往下执行，不满足则释放mutex继续等待
		_notEmpty.wait(locker, [this] {return _needStop || notEmpty(); });
		
		if (_needStop) {
			return;
		}
		//移动语义
		list = move(_queue);
		//通知等待添加任务的线程
		_notFull.notify_one();
	}

	void Take(T& t) {
		unique_lock<mutex> locker(_mutex);
		//当处于waiting状态的线程被notify_one 或 notify_all时，获取到mutex，然后判断调整是否满足，如果满足则往下执行，不满足则释放mutex继续等待
		_notEmpty.wait(locker, [this] {return _needStop || notEmpty(); });

		if (_needStop) {
			return;
		}
		//移动语义
		t = _queue.front();
		_queue.pop_front();
		//通知等待添加任务的线程
		_notFull.notify_one();
	}

	void Stop() {
		{
			unique_lock<mutex> locker(_mutex);
			_needStop = true;
		}
		//唤醒所有等待的线程，减少locker的粒度进行优化
		_notEmpty.notify_all();
		_notFull.notify_all();
	}

	bool Empty() {
		lock_guard<mutex> locker(_mutex);
		return _queue.empty();
	}

	bool Full() {
		lock_guard<mutex> locker(_mutex);
		return _queue.size() == _maxSize : true : false;
	}

	size_t Size() {
		lock_guard<mutex> locker(_mutex);
		return _queue.size();
	}
private:

	bool notEmpty() {
		return _queue.size() > 0 : true : false;
	}

	bool notFull() {
		return _queue.size() < _maxSize : true : false;
	}

	template<typename F>
	void Add(F&& x) {
		unique_lock<mutex> locker(_mutex);
		//队列已满时等待，等待通知
		_notFull.wait(locker, [this] {return _needStop || notFull(); });

		if (_needStop) {
			return;
		}

		//参数&& 为右值引用，采用完美转发
		_queue.push_back(forward<F>(x));
		//通知等待获取任务的线程
		_notEmpty.notify_one();
	}
};