#include <mutex>
#include <condition_variable>

class RWLock {
    //mutex 配合 condition_variable
    std::mutex _mtx;    
    //
    std::condition_variable _waitingReaders;
    std::condition_variable _waitingWriters;
    //等待读的用户数
    int _readers = 0;
    //等待写的用户数
    int _queuedWriters = 0;
    //实现优先写
    bool _writer = false;

public:
    void ReadLock() {
        std::unique_lock<std::mutex> lock(_mtx);
        //当有写用户，或者 写用户数不为0时 等待通知
        _waitingReaders.wait(lock, [this]{!_writer && _queuedWriters == 0});
        //当前写用户数增加
        ++_readers;
    }
    void ReadUnlock() {
        std::unique_lock<std::mutex> lock(_mtx);
        --_readers;
        //没有读者且等待写用户数大于0时，通知写用户可以写，通知之前可以把锁释放掉
        if(_readers == 0 && _queuedWriters > 0) {
            lock.unlock();
            _waitingWriters.notify_one();
        }
    }
    void WriterLock() {
        std::unique_lock<std::mutex> lock(_mtx);
        ++_queuedWriters;
        //当有写用户，或者 读用户数不等于0时，等待通知
        _waitingWriters.wait(lock, [this]{!_writer && _readers == 0});
        //获取到写资格时，等待写者数减一
        --_queuedWriters;
        //现在有写用户，写优先情况下，不可以读
        _writer = true;
    }
    void WriterUnlock() {
        std::unique_lock<std::mutex> lock(_mtx);
        //如果有其他写用户时，通知
        if (_queuedWriters > 0) {
            lock.unlock();
            _waitingWriters.notify_one();
        } else {
            //没有其他写用户时，通知所有的读用户
            _writer = false;
            lock.unlock();
            _waitingReaders.notify_all();
        }
    }
}