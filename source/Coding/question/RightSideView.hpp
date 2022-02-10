#pragma once

/// <summary>
/// leetCode 199
/// 输出二叉树的右视图
/// 
/// </summary>

#include <vector>
#include <queue>
#include "CommonStruct.h"

using namespace std;

class RightSideView {
public:
	static vector<int> GetRightSideView(TreeNode* root) {
		vector<int> ans = {};
		if (nullptr == root) {
			return ans;
		}

		queue<TreeNode*> levelQueue;
		levelQueue.push(root);
		while (!levelQueue.empty()) {

			int count = levelQueue.size();
			for (int i = 0; i < count; ++i) {

				TreeNode* node = levelQueue.front();
				levelQueue.pop();

				if (node->left) levelQueue.push(node->left);
				if (node->right) levelQueue.push(node->right);

				//最后一个节点即为当前层最右节点
				if (i == count - 1) {
					ans.push_back(node->val);
				}


			}
		}

		return ans;
	}
};