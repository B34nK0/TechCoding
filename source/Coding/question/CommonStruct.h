#pragma once

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {

	}
	ListNode(int x) :val(x), next(nullptr) {

	}
	ListNode(int x, ListNode*) :val(x), next(nullptr) {

	}

	ListNode(int x, int n) :val(x), next(nullptr) {
		ListNode* head = this;
		for (int i = 1; i < 5; ++i) {
			ListNode* l2 = new ListNode();
			l2->val = i;
			head->next = l2;
			head = head->next;
		}
	}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};