#pragma once

#include "CommonStruct.h"
/// <summary>
/// leetCode 21 合并两个升序链表
/// </summary>
class MergeTwoLists {
public:
	static ListNode* GetMergeRes(ListNode* l1, ListNode* l2) {
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
		ListNode ans, * tail = &ans;

		//当前的进位值
		int curIncr = 0;
		//遍历两个链表
		int curValue = 0;
		while (l1 != nullptr || l2 != nullptr) {
			curValue = 0;
			if (l1 == nullptr) {
				curValue = l2->val + curIncr;
				l2 = l2->next;
			}
			else if (l2 == nullptr) {
				curValue = l1->val + curIncr;
				l1 = l1->next;
			}
			else {
				curValue = l1->val + l2->val + curIncr;
				l1 = l1->next;
				l2 = l2->next;
			}

			curIncr = curValue / 10;
			curValue = curValue % 10;

			ListNode* n = new ListNode(curValue);
			tail->next = n;
			tail = tail->next;
		}

		if (curIncr > 0) {
			ListNode* n = new ListNode(curIncr);
			tail->next = n;
		}

		return ans.next;
	}
};