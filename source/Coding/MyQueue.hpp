/*
leetCode 232 用栈实现队列
使用两个栈  输入栈、输出栈 来
*/
#include <stack>
class MyQueue {
    std::stack<int> input;
    std::stack<int> output;
public:
    MyQueue() {

    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        //如果输出栈当前为空，那么将输入栈的数据转移到输出栈，实现先入栈的在输出栈的栈顶
        //从输出栈栈顶开始获取数据即实现队列的先进先出特性
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return output.empty() ? input.empty() : false;
    }
};