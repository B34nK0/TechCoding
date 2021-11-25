#include<list>
#include<thread>
#include<functional>
#include<atomic>
//同步队列
#include"SyncQueue.hpp"

using Task = std::function<void()>;
const int MaxTaskCount = 100;
class ThreadPool {
private:
    //池里维护的线程
    std::list<std::shared_ptr<std::thread>> _threadgroup;
    //处理的任务数
    SyncQueue<Task> _queue;
    //是否停止
    atomic_bool _running;
    //用户确保stop只调用一次
    std::once_flag = _flag;
public:
    //默认初始化队列
    ThreadPool(int defaultThread = std::thread::hardware_concurrency()):_queue(MaxTaskCount) {
        start(defaultThread);
    }    

    ~ThreadPool() {
        stop();
    }

    void AddTask(Task&& task) {
        _queue.put(std::forward<Task>(task));
    }

    void AddTask(const Task&& task) {
        _queue.put(task);
    }
private:
    //预创建线程
    start(int defaultThread) {
        _running = true;
        //创建线程
        for (int i = 0; i < defaultThread; ++i) {
            //绑定线程执行函数
            _threadgroup.push_back(std:make_shared<std::thread>(&ThreadPool::runInThread,this));
        }
    }
    //
    runInThread() {
        while (_running) {
            //从队列获取任务消费
            std::list<Task> list;
            _queue.Take(list);

            for (auto& task : list) {
                if (!_running) {
                    return;
                    //执行任务
                    task();
                }
            }
        }
    }
    //析构线程池的使用调用停止
    stop() {
        std::call_once(_flag,[this]{stopAllThread();});
    }
    //
    stopAllThread() {
        //停止队列，在退出线程池之前，是否需要处理完队列内的任务取决于业务场景
        _queue.stop();
        //退出工作线程
        _running = false;
        //
        for (auto thread : _threadgroup) {
            if (thread) {
                thread->join();
            }
        }
        _threadgroup.clear();
    }

};