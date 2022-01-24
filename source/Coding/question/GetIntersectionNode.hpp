#pragma once

/// <summary>
/// leetcode 160
/// 判断两个链表是否有相交，有则返回相交的节点，无则返回null
/// </summary>
/// 

#include "CommonStruct.h"
#include <unordered_set>
using namespace std;

class GetIntersectionNode {
public:
	ListNode* GetNode(ListNode* headA, ListNode* headB) {
		//采用hash值方式判断链表b所遍历的节点是否已在链表a中存在
		unordered_set<ListNode*> firstListNode;
		while (headA) {
			firstListNode.insert(headA);
			headA = headA->next;
		}

		while (headB) {
			auto itr = firstListNode.find(headB);
			if (itr != firstListNode.end()) {
				return *itr;
			}
			headB = headB->next;
		}
		return nullptr;
	}

	//采用双指针方式，原理在于让链表A能与链表B互为环
	ListNode* Func2(ListNode* headA, ListNode* headB) {
		ListNode* ptrA = headA;
		ListNode* ptrB = headB;

		if (ptrA == nullptr || ptrB == nullptr) {
			return nullptr;
		}

		while (ptrA != ptrB) {

			if (ptrA == nullptr) {
				ptrA = headB;
			}
			else {
				ptrA = ptrA->next;

			}

			if (ptrB == nullptr) {
				ptrB = headA;
			}
			else {
				ptrB = ptrB->next;

			}
		}

		return ptrA;
	}
};