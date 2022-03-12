/*
* leetCode 102
锯齿形输出二叉树，即从左节点到右节点输出一层后，输出下一层的反方向顺序（右到左）
[3, 9, null,null, 20, 15, 7]
[3,[20, 9],[15, 7]]

采用广度优先搜索，对树进行逐层遍历。比如root根节点为奇数层，即从左到右，偶数层即从右到左顺序输出节点
*/

#include "CommonStruct.h"
#include <vector>
#include <queue>

using namespace std;
class ZigzagLevelOrder {
public:
	vector<vector<int>> revert(TreeNode* root) {
		//二维数组存储每层节点值
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}

		//存放树节点用于广度优先搜索
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		//初始化奇数层采用从左到右顺序
		bool isLeftNode = true;
		
		//拿出每层的节点进行输出
		while (!nodeQueue.empty()) {
			int levelSize = nodeQueue.size();
			//双端队列用于存放每层节点顺序
			deque<int> nodeValues;
			//先遍历当前层节点
			for (int i = 0; i < levelSize; ++i) {
				TreeNode* node = nodeQueue.front();
				nodeQueue.pop();
				//根据当前奇偶数层放置节点
				if (isLeftNode) {
					nodeValues.push_back(node->val);
				}
				else {
					nodeValues.push_front(node->val);
				}
				//把节点的子节点放到节点队列用于下一层遍历
				if (node->left) {
					nodeQueue.push(node->left);
				}
				if (node->right) {
					nodeQueue.push(node->right);
				}
			}
			//输出当前层
			ans.emplace_back(vector<int>{nodeValues.begin(), nodeValues.end() });
			isLeftNode = !isLeftNode;
		}

		return ans;
	}
};