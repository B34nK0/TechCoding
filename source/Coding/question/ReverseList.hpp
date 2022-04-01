#pragma once
/*
* leetCode 206
反转链表

先虚构pre节点为nullptr，开始遍历链表
1、采用next记录当前节点的next
2、当前节点next指向pre
3、pre指向当前节点
4、完成当前节点的断开后，当前节点指向next，再循环遍历

最后pre为反转后的头节点
*/

#include <CommonStruct.h>

class ReverseList {
public:
	ListNode* Reverse(ListNode* head) {
		
		ListNode* pre = nullptr;
		ListNode* curr= head;
		while (curr) {
			ListNode* next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}

		return pre;
	}
};