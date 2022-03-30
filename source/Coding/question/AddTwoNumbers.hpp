/*
leetCode 2两数相加
*/

#include "CommonStruct.h"
class AddTwoNumbers {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
			return l2;
		}
		if (l2 == nullptr) {
			return l1;
		}
		if (l1 == nullptr && l2 == nullptr) {
			return nullptr;
		}
		//先制造空节点用于指向要返回的结果链表头
		ListNode pre;
		ListNode* head = pre.next;

		//当前的进位值
		int curIncr = 0;
		//遍历两个链表
		int curValue = 0;
		while (l1 != nullptr || l2 != nullptr) {
			if (l1 == nullptr) {
				curValue = l2->val;
				l2 = l2->next;
			}
			else if (l2 == nullptr) {
				curValue = l1->val;
				l1 = l1->next;
			}
			else {
				curValue = l1->val + l2->val;
				l1 = l1->next;
				l2 = l2->next;
			}

			curIncr = curValue / 10;
			curValue = curValue % 10;

			ListNode* n = new ListNode(curValue);
			head->next = n;
			head = head->next;
		}

		if (curValue > 0) {
			ListNode* n = new ListNode(curValue);
			head->next = n;
		}

		return pre.next;
	}
};