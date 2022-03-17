#include "CommonStruct.h"

/*
leetCode 142 环形链表 II

判断链表为环，输出环的入口节点
*/
class DetectCycle {
public:
    ListNode* GetDetectCycleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr) {
            if (fast->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* entry = head;
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;

            }
        }

        return nullptr;
    }
};