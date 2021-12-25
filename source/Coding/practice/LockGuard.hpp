// 局部锁

struct mutex {
    void Lock(){}
    void Unlock(){}
};
//采用RAII方式确保资源被释放
struct LockGuard {
    //struct默认方法为public
    LockGuard(mutex& _mutex) : _scopeMutex(_mutex){
        _scopeMutex.Lock();
    }

    ~LockGuard() {
        _scopeMutex.Unlock();
    }
private:
    mutex& _scopeMutex;
    //private禁止对象拷贝复制
    LockGuard(const LockGuard&);
    LockGuard& operator=(const LockGuard&);
};