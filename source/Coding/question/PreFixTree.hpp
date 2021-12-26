/*
前缀树 也叫字典树，常用于压缩字典内容
*/

#include <string>
using namespace std;

class PreFixTree {
	struct Node {
		//需要确认字符内容不超过26个字母
		Node* child[26];
		bool isWord;
		//初始化子节点为nullptr
		Node() {
			for (int i = 0; i < 26; i++) {
				child[i] = nullptr;
			}
			isWord = false;
		}
	};

	Node* root;
public:
	PreFixTree() {
		root = new Node();
	}

	void Insert(string word) {
		Node* curr = root;
		for (auto ch : word) {
			int index = ch - 'a';
			//已存在相同字符的节点，继续遍历
			if (curr->child[index]) {
				curr = curr->child[index];
				continue;
			}
			//新建节点
			curr->child[index] = new Node;
			curr = curr->child[index];
		}
		curr->isWord = true;
	}

	bool Search(string word) {
		Node* curr = root;

		for (auto ch : word) {
			int index = ch - 'a';
			//不存在节点
			if (!curr->child[index]) {
				return false;
			}
			curr = curr->child[index];
		}
		return curr->isWord ? true : false;
	}
};