/*
按层次输出二叉树节点
*/

#include <vector>
#include <queue>
#include <CommonStruct.h>

using namespace std;

class LevelOrder {
public:
	vector<vector<int>> ConvertTreeNode(TreeNode* root) {
		vector<vector<int>> result;
		if (nullptr == root) return result;

		//分别放置父节点 、子节点
		queue<TreeNode*> parentQ, childrenQ;
		parentQ.push(root);
		while (!parentQ.empty() || !childrenQ.empty()) {
			//分别指向当前输出层次的队列、放置对应子节点的队列
			queue<TreeNode*>* putQ, * getQ;
			//
			putQ = parentQ.empty() ? &parentQ : &childrenQ;
			getQ = parentQ.empty() ? &childrenQ : &parentQ;

			//同一层节点
			vector<int> level;
			while (!getQ->empty()) {
				//getQ的节点为当前空一层节点待输出
				TreeNode* curr = getQ->front();
				level.push_back(curr->val);
				//节点若有子节点时放置到put队列
				if (curr->left) putQ->push(curr->left);
				if (curr->right) putQ->push(curr->right);
				getQ->pop();
			}
			result.push_back(level);
		}

		queue<TreeNode*> putQ, getQ;
		putQ.push(root);

		vector<int> level;
		while (!putQ.empty() || !getQ.empty()) {
			while (!putQ.empty()) {
				TreeNode* curr = putQ.front();
				level.push_back(curr->val);
				if (curr->left) getQ.push(curr->left);
				if (curr->right) getQ.push(curr->right);
				putQ.pop();
			}
			level.clear();
			result.push_back(level);

			while (!getQ.empty()) {
				TreeNode* curr = getQ.front();
				level.push_back(curr->val);
				if (curr->left) putQ.push(curr->left);
				if (curr->right) putQ.push(curr->right);
				getQ.pop();
			}
			level.clear();
			result.push_back(level);
		}

		return result;
	}

};