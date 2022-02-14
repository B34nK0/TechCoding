#pragma once

/// <summary>
/// leetCode 合并k个升序链表
/// </summary>
/// 
#include "CommonStruct.h"
#include <vector>

using namespace std;

class MergeKLists {
public:
	//合并两个链表时需要采用升序
	static ListNode* mergeTwoList(ListNode* leftList, ListNode* rightList) {
		//有一链表为空， 那么返回不为空的链表即可
		if (!leftList || !rightList) {
			return leftList ? leftList : rightList;
		}
		//head.next衔接节点， tail.next用于变动 所有tail初始指向head，可用于返回表头
		ListNode head, *tail = &head, *pa = leftList, *pb = rightList;
		//指向双链表当前节点，用于判断两边节点大小
		while (pa && pb) {
			if (pa->val < pb->val) {
				tail->next = pa;
				pa = pa->next;
			}
			else {
				tail->next = pb;
				pb = pb->next;
			}
			tail = tail->next;
		}
		//将pa\pb剩余的接到链表里
		tail->next = (pa ? pa : pb);

		return head.next;
	}

	static ListNode* merge(vector<ListNode*>& lists, int l , int r) {
		//采用递归的方式分而治之合并两个链表，当l大于r时不合理
		if (l > r) return nullptr;
		//当l等于r时，只有一个链表
		if (l == r) return lists[l];
		//采用中点方式
		int mid = (l + r) >> 1; //右移1相当于除2，右移n位相当于除2的n次方
		//采用mid下标
		return mergeTwoList(merge(lists, l , mid), merge(lists, mid+1, r));
	}

	static ListNode* GetResult(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}
};