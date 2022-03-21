#pragma once
/*
leetCode 234 回文链表

*/

#include "CommonStruct.h"

class IsPalindrome {
	ListNode* frontPoint;
public:
	bool recursivelyCheck(ListNode* currentNode) {
		//遇到尾节点结束，向上冒
		if (currentNode == nullptr) {
			return true;
		}
		if (!recursivelyCheck(currentNode->next)) {
			return false;
		}
		//节点值不相等，直接返回错误
		if (currentNode->val != frontPoint->val) {
			return false;
		}
		//节点值相等，头指针向下，尾指针向上
		frontPoint = frontPoint->next;
		return true;
	}

	//方法一：采用递归的方式
	bool check1(ListNode* head) {
		//
		frontPoint = head;
		return recursivelyCheck(head);
	}


	//方法二：反转后半部分链表之后比对前后半段链表是否值相等
	bool check2(ListNode* head) {
		//先找出中间节点
		ListNode* firstHalfEnd = endOfFirstHalf(head);
		//反转后半部分链表
		ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
		ListNode* p1 = head;
		ListNode* p2 = secondHalfStart;
		bool result = true;
		while (result && p2 != nullptr) {
			if (p1->val != p2->val) {
				result = false;
			}
			p1 = p1->next;
			p2 = p2->next;
		}

		//反转回后半段链表
		firstHalfEnd->next = reverseList(secondHalfStart);
		return result;
	}

	//采用快慢指针，找出链表的中间节点
	ListNode* endOfFirstHalf(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (slow->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	//反转链表，返回新的头结点
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur != nullptr) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};