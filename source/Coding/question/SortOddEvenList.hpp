
/*
给定一个奇数位升序，偶数位降序的链表，将其重新排序。

输入: 1->8->3->6->5->4->7->2->NULL
输出: 1->2->3->4->5->6->7->8->NULL
*/

#include "CommonStruct.h"


class SortOddEvenList {
public:
	static void Sort(ListNode* node) {
		//将原链表拆解成奇、偶两个链表
		tuple<ListNode*, ListNode*> res =  partition(node);
		//反转偶链表
		ListNode* evenHead = std::get<1>(res);
		evenHead = revers(evenHead);
		//合并两个链表
		ListNode* oddHead = std::get<0>(res);
		node = merge(oddHead, evenHead);
	}

	static tuple<ListNode*, ListNode*> partition(ListNode* node) {
		ListNode* oddHead = nullptr, * evenHead = nullptr;
		ListNode* curOdd = nullptr, * curEven = nullptr;
		while (node) {
			//odd
			if (node->val % 2) {
				if (!oddHead) {
					oddHead = new ListNode(node->val);
					curOdd = oddHead;
				}
				else {
					curOdd->next = new ListNode(node->val);
					curOdd = curOdd->next;
				}
			}
			else {//even
				if (!evenHead) {
					evenHead = new ListNode(node->val);
					curEven = evenHead;
				}
				else {
					curEven->next =  new ListNode(node->val);
					curEven = curEven->next;
				}
				curEven->next = nullptr;
			}

			node = node->next;
		}

		return tuple<ListNode*, ListNode*>(oddHead, evenHead);
	}

	static ListNode* revers(ListNode* head) {
		ListNode* pre = nullptr, *next = nullptr;
		ListNode* cur = head;
		while (cur) {
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}

	static ListNode* merge(ListNode* oddHead, ListNode* evenHead) {
		//制造一个空节点
		ListNode ans, *tail = &ans;

		while (oddHead && evenHead) {
			if (oddHead->val <= evenHead->val) {
				tail->next = oddHead;
				oddHead = oddHead->next;
			}
			else {
				tail->next = evenHead;
				evenHead = evenHead->next;
			}

			tail = tail->next;
		}

		oddHead ? tail->next = oddHead : tail->next = evenHead;

		return ans.next;
	}
};