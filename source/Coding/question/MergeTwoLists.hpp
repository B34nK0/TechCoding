#pragma once

#include "CommonStruct.h"
/// <summary>
/// leetCode 21 合并两个升序链表
/// </summary>
class MergeTwoLists {
public:
	static ListNode* GetMergeRes(ListNode* listA, ListNode* listB) {
		if (!listA || !listB) {
			return listA ? listA : listB;
		}
		//制造一个空节点
		ListNode ans, *tail = &ans;

		//遍历两个链表进行判断
		while (listA && listB) {
			if (listA->val < listB->val) {
				tail->next = listA;
				listA = listA->next;
			}
			else {
				tail->next = listB;
				listB = listB->next;
			}
			tail = tail->next;
		}

		listA ? tail->next = listA : tail->next = listB;
		return ans.next;
	}
};