/*
leetCode 46 全排列
给定一个不含重复数字的数组，全排列出所有的组合
*/

#include <vector>

using namespace std;
class Permute {
public:
	void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
		if (first == len) {
			res.emplace_back(output);
			return;
		}

		for (int i = first; i < len; ++i) {
			swap(output[i], output[first]);
			backtrack(res, output, first + 1, len);
			swap(output[i], output[first]);
		}
	}

	vector<vector<int>> GetResult(vector<int>& nums) {
		vector<vector<int>> res;

		backtrack(res, nums, 0, nums.size());

		return res;
	}
};