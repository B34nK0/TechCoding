#pragma once

#include <CommonStruct.h>
#include <utility>
#include <tuple>
/*
*leetCode 25 k个一组反转链表
* 给定一个链表，及参数k，将链表按每k个节点为一组进行翻转
* 1->2->3->4->5 k=2
* 2->1->4->3->5
*/

using namespace std;
class ReverseKGroupList {
public:
	//返回反转后的头、尾节点位置
	static pair<ListNode*, ListNode*> reverseSubList(ListNode* head, ListNode* tail) {
		//将子链表尾节点的下一个节点作为当前的前节点
		ListNode* prev = tail->next;
		ListNode* curr = head;
		//反转链表
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