#include <utility>

#include "CommonStruct.h"
/*
* 
* leetCode 124
计算二叉树的最大路径和

如：
-10
/	\
9	 20
	/	\
	15   7

最大路径和为 15->20->7

*/


using namespace std;
class MaxPathSum {

public:
	static int maxSum;


	static int MaxSum(TreeNode* treeNode) {
		maxGain(treeNode);
		return maxSum;
	}

	static int maxGain(TreeNode* treeNode) {
		if (nullptr == treeNode) {
			return 0;
		}

		//当前节点的路径值 等于 当前值 + 左右节点的贡献值，为负的节点不计算入内
		int curGain = treeNode->val;

		//递归计算左右节点的贡献值
		int leftGain = max(maxGain(treeNode->left), 0);
		curGain += leftGain;

		int rightGain = max(maxGain(treeNode->right), 0);
		curGain += rightGain;

		//与记录的最大路径值比较
		maxSum = max(maxSum, curGain);

		//当前节点的贡献值等于当前值+左右子节点的最大贡献值
		//将当前左中还是右中的路径提供给父节点
		return treeNode->val + max(leftGain, rightGain);
	}
};

int MaxPathSum::maxSum = INT_MIN;;