#pragma once

/// <summary>
/// leetCode 105 从前序与中序遍历序列构造二叉树
/// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
/// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
/// 输出: [3, 9, 20, null, null, 15, 7]
/// </summary>
/// 
#include "CommonStruct.h"
#include <vector>
#include <unordered_map>

using namespace std;
class BuildTree {
public:
	//key为根节点在前序数组中的位置，value为根节点在中序数组中的位置，用于划分左右子树
	unordered_map<int, int> nodeIndex;

	//递归，自底向上构建树,当数组为空时，说明已经没有叶子节点了
	TreeNode* getChildren(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
		if (preorder_left > preorder_right) {
			return nullptr;
		}
		//先分别在中序、前序中定位出根节点
		// 
		//节点必然时前序的第一个元素
		int preorder_root = preorder_left;
		//nodeIndex记录了值在中序中的位置
		int inorder_root = nodeIndex[preorder[preorder_root]];

		//构建当前层的节点用于返回给上层，作为上层的子节点
		TreeNode* root = new TreeNode(preorder_root);
		//得到左子树的长度
		int left_sub_tree = inorder_root - inorder_left;

		root->left = getChildren(preorder, inorder, preorder_left + 1, preorder_left + left_sub_tree, inorder_left, inorder_root - 1 );

		root->right = getChildren(preorder, inorder, preorder_left + left_sub_tree + 1, preorder_right, inorder_root + 1, inorder_right);

		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; ++i) {
			//记录节点值在数组中的位置，用于计算左右子树的长度用于截取前序
			nodeIndex[inorder[i]] = i;
		}

		return getChildren(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};