/*
leetCode 155 最小栈
实现可获取当前最小值的栈
*/
#include <algorithm>

using namespace std;
class Node {
public:

    int val;
    int min;

    Node* next;

    Node(int v, int m) : val(v), min(m), next(nullptr) {}

    Node(int v, int m, Node* n) : val(v), min(m), next(n) {}
};

class MinStack {

public:
    Node* head;
    int _min_val;

    MinStack() {
        head = nullptr;
    }

    void push(int val) {
        if (head) {
            head = new Node(val, min(val, head->min), head);
        }
        else {
            head = new Node(val, val);
        }
    }

    void pop() {
        if (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->min;
    }
};