/*
* leetCode 98
* 
判断树是否为二叉查找树

二叉搜索树的定义
左子树只包含小于当前节点的数
右子树只包含大于当前节点的数
左子树和右子树自身必须是二叉搜索树
*/

#include "CommonStruct.h"

class IsValidBSTHelper {
public :
	bool IsValidBST(TreeNode* root) {
		return isValid(root, nullptr, nullptr);
	}
	//采用dfs的思路，向下判断每个子树是否符合二叉搜索树
	bool isValid(TreeNode* root, TreeNode* leftChild, TreeNode* rightChild) {
		
		if (!root) return true;

		//左子树值大于n节点 或者 右子树值大于n节点 时，说明不符合二叉搜索树的定义，返回false
		if ((leftChild && leftChild->val >= root->val) || (rightChild && rightChild->val <= root->val)) {
			return false;
		}

		//左子树：以当前节点为根节点，原父节点值应该大于该值，父节点的父节点值应该小于当前值
		//右子树：以当前节点为根节点，原父节点值应该小于该值，父节点的父节点值应该大于当前值
		return isValid(root->left, leftChild, root) && isValid(root->right, root, rightChild);
	}
};