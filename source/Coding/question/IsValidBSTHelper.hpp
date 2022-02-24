/*
判断树是否为二叉查找树
*/

#include "CommonStruct.h"

class IsValidBSTHelper {
public :
	bool IsValidBST(TreeNode* root) {
		return isValid(root, nullptr, nullptr);
	}

	bool isValid(TreeNode* root, TreeNode* leftChild, TreeNode* rightChild) {
		
		if (!root) return true;

		//左子树值大于n节点 或者 右子树值大于n节点
		if ((leftChild && leftChild->val >= root->val) || (rightChild && rightChild->val <= root->val)) {
			return false;
		}

		return isValid(root->left, leftChild, root) && isValid(root->right, root, rightChild);
	}
};