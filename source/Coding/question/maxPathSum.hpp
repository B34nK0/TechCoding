#include <utility>


/*
计算二叉树的最大路径和

如：
-10
/	\
9	 20
	/	\
	15   7

最大路径和为 15->20->7

*/

class TreeNode {
public:
	int value;

	TreeNode* left;

	TreeNode* right;
};

using namespace std;
class MaxPathSum {
private:
	int _maxSum = 0;

public:

	static int MaxSum(TreeNode* treeNode) {
		if (nullptr == treeNode) {
			return 0;
		}


	}

private:
	/// <summary>
	/// 计算每个节点的贡献值
	/// </summary>
	/// <param name="treeNode"></param>
	/// <returns></returns>
	int maxGain(TreeNode* treeNode) {
		if (nullptr == treeNode) {
			return 0;
		}

		//当前节点的贡献值 等于 左右节点的贡献值，为负的节点不计算入内
		int curGain = treeNode->value;

		//递归计算左右节点的贡献值
		int leftGain = maxGain(treeNode->left);
		if (leftGain > 0) {
			curGain += leftGain;
		}

		int rightGain = maxGain(treeNode->right);
		if (rightGain > 0) {
			curGain += rightGain;
		}

		//最大路径和 当前节点为负节点时， 累加左右节点仍然为负的情况，即不可计算入内
		_maxSum = max(_maxSum, _maxSum + curGain);

		//返回左中， 由还是 右中节点
		return treeNode->value + max(leftGain, rightGain);
	}
};