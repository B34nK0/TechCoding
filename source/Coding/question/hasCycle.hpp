#pragma once

class ListNode {
public :
    ListNode* next = nullptr;
};

class cycleListSolution {
public:
    bool hasCycle(ListNode* head) {
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