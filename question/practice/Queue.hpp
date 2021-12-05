#include <queue>
#include <mutex>
#include <condition_variable>
//线程安全的queue
template<typename T>
class Queue {
private:
    std::queue<T> _q;
    //队列锁
    std::mutex _mtx;
    //条件变量，当队列不为空时通知pop
    std::condition_variable _cv;

public:
    void pop(T& item) {
        std::unique_lock<std::mutex> mtx(_mtx);
        while(_q.empty) {
            _cv.wait(mtx);
        }
        item = _q.front();
        _q.pop();
    }

    void push(const T& item) {
        std::unique_lock<std::mutex> mtx(_mtx);
        mtx.lock();
        _q.push(item);
        mtx.unlock();
        _cv.notify_one();
    }
};