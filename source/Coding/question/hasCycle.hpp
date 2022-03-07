#pragma once

#include <CommonStruct.h>

/*
leetCode 141 环形链表
采用快慢指针的方式，当快慢指针相遇时说明有环，当快指针为null时说明不成环
*/
class HasCycle {
public:
    bool ListHasCycle(ListNode* head) {
        if (nullptr == head || head->next == nullptr) {
            return false;
        }

        ListNode* p1 = head;
        ListNode* p2 = head->next->next;
        while (p1 != p2) {
            if (nullptr == p2 || nullptr == p2->next) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next->next;
        }

        return true;
     
    }
};