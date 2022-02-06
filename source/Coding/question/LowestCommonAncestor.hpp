#pragma once

#include <CommonStruct.h>
/// <summary>
/// leetCode 236
/// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
/// </summary>
class LowestCommonAncestor {
public:
    TreeNode* GetCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        //当前节点等于指定节点中的某一个，那么当前节点或者其父节点即为最近公共祖先
        if (root == p || root == q) return root;

        //从左子树查看是否含有指定节点
        TreeNode* leftNode = GetCommonAncestor(root->left, p, q);
        //从右子树查看是否含有指定节点
        TreeNode* rightNode = GetCommonAncestor(root->right, p, q);

        //当前节点为最近公共祖先
        if (leftNode && rightNode ) return root;

        //左子树有指定节点
        if (leftNode != nullptr) return leftNode;
        //右子树有指定节点
        if (rightNode != nullptr) return rightNode;
    }
};