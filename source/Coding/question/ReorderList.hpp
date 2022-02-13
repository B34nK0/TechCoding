
//leetCode 143 重排链表
//原 l1 - l2 - l3 - l4 - l5
//结 l1 - l5 - l2 - l4 - l3

#include "CommonStruct.h"

class ReorderList {
public:
	static void GetReorderList(ListNode* head) {
		if (nullptr == head) {
			return;
		}
		//先找出链表中点
		ListNode* mid = getMidNode(head);
		//将链表从中点分成左右两个链表
		ListNode* left = head;
		ListNode* right = mid->next;
		mid->next = nullptr;
		//将右链表进行反转
		right = reverseList(right);
		//合并左右链表
		mergeList(left, right);
	}

	static ListNode* getMidNode(ListNode* head) {
		//采用双指针方式，p1每次走一步， p2每次走两步，当p2为nullptr时，p1即为中间节点
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}

	static ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr,*next = nullptr;
		ListNode* cur = head;
		while (cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}

		return prev;
	}

	static void mergeList(ListNode* left, ListNode* right) {
		while (left && right) {
			ListNode* leftTmp = left->next;
			ListNode* rightTmp = right->next;

			left->next = right;
			left = leftTmp;

			right->next = left;
			right = rightTmp;
		}
	}
};