#pragma once

#include <CommonStruct.h>
#include <utility>
#include <tuple>
/*
* k个一组反转链表
*/

using namespace std;
class ReverseKGroupList {
public:
	//返回新的头、尾节点位置
	static pair<ListNode*, ListNode*> reverseSubList(ListNode* head, ListNode* tail) {
		//字列表的尾指向的是下一个子列表
		ListNode* prev = tail->next;
		ListNode* curr = head;
		while (prev != tail) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return { tail, head };
	}

	static ListNode* Reverse(ListNode* head, int k) {
		ListNode* hair = new ListNode();
		hair->next = head;
		ListNode* pre = hair;
		while (head) {
			ListNode* tail = pre;

			//获取子链表在k组内的头、尾节点位置
			// 查看剩余部分长度是否大于等于 k
			for (int i = 0; i < k; ++i) {
				tail = tail->next;
				if (!tail) {
					return hair->next;
				}
			}

			//子链表尾直线的是下一个子链表，缓存起来用于开始下一次子链表
			ListNode* next = tail->next;
			//返回子列表的反转列表
			tie(head, tail) = reverseSubList(head, tail);
			pre->next = head;
			tail->next = next;
			pre = tail;
			//反转下一个子链表
			head = tail->next;
		}

		return hair->next;
	}
};