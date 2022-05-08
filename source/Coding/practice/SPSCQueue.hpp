// 单生产者单消费者模式

#include <assert.h>
#include <vector>
#include <atomic>

template <typename T>
class SPSCQueue {
private:
    //cacheline size为64位， 我们可采用64位内存对齐方式
    alignas(64) std::atomic<int> _readPos;//缓冲区读位置

    alignas(64) std::atomic<int> _writePos;//缓冲区写位置

    //64 - 4,需要填充60位
    char _padding[64 - sizeof(_writePos)];
    //采用数组来存放队列数据
    //32位
    std::vector<T> _buffer;

private:
    //内敛函数的作用在于编译时编译器在内联函数调用的位置嵌入函数体的内容，减少函数调用
    //该函数返回消息存入队列缓冲数组的位置
    inline int increment(int pos) const {
        return (pos + 1) % int(_buffer.size());
    }
public:
    SPSCQueue(int capacity) : _buffer(capacity + 1), _readPos(0), _writePos(0) {
        assert(capacity > 0);
        //capacity是个有符号值，存在溢出情况
        assert(capacity + 1 > 0);
    }

    bool push_back(const T &item) {
        //读取 readPos值，保证其他线程在load之后的读写操作不会发生在load之前
        const int r = _readPos.load(std::memory_order_acquire);
        //读取 writePos的值， relaxed保证的是当前线程的writePos值操作的顺序一致性
        const int w = _writePos.load(std::memory_order_relaxed);

        //获取写入位置
        const int next_w = increment(w);
        //写入位置等于读取位置，说明队列已经满了
        if (r == next_w) return false;

        _buffer[w] = item;
        //保证其他线程在store之前对writePos值的的读写操作不会发生在store之后
        _writePos.store(next_w, std::memory_order_release);
        return true;
    }

    bool pop_front(T &item) {
        //当前线程顺序
        int r = _readPos.load(std::memory_order_relaxed);
        //保证其他线程在load之后的读写操作不会发生在load之前
        int w = _writePos.load(std::memory_order_acquire);

        //队列为空  
        if (r == w) return false;

        item = _buffer[r];
        _readPos.store(increment(r), std::memory_order_release);
        return true;
    }
};