#pragma once

class ListNode {
public:
	ListNode* next = nullptr;
};

/// <summary>
/// 移除单向链表倒数第n个节点
/// 可以设置两个指针，p1 p2 ，p2比p1先前进n个节点，然后同时移动p1,p2
/// 当p2先到达链尾时，说明p1即在倒数第n个节点上
/// </summary>
class RemoveNthFromEnd {
public:
	static ListNode* Remove(ListNode* head, int n) {
		ListNode* p1, * p2, * prev;
		prev = p1 = p2 = head;
		while (n--) {
			p2 = p2->next;
		}

		while (p2) {
			prev = p1;
			p1 = p1->next;
			p2 = p2->next;
		}

		//移除倒数第n个节点
		prev->next = p1->next;

		return head;
	}
};