#pragma once

/// <summary>
/// leetCode 101 对称二叉树
/// 假设根节点开始左右子树 分为两棵树，若为对称时，这两棵树互为镜像
/// root = [1,2,2,3,4,4,3] return true;
/// </summary>

#include "CommonStruct.h"
class IsSymmetric {
public:
	bool isMirrorTree(TreeNode* leftRoot, TreeNode* rightRoot) {
		//均为nullptr时对称
		if (!leftRoot && !rightRoot) {
			return true;
		}
		//节点其中有一个为nullptr时不对称
		if (!leftRoot || !rightRoot) {
			return false;
		}
		//两节点都不为空，那么需要判断值是否一直
		if (leftRoot->val != rightRoot->val) {
			return false;
		}
		//假设树A 树B 互为镜像
		//开始递归子节点，因为互为镜像时，应该对比A左子节点与B右子节点，对比A右子节点与B左子节点
		if (isMirrorTree(leftRoot->left, rightRoot->right) && isMirrorTree(leftRoot->right, rightRoot->left)) {
			return true;
		}

		return false;
	}

	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) {
			return false;
		}

		return isMirrorTree(root, root);
	}
};