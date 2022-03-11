#pragma once

/*
leetCode 39 组合总和
给不重复数字的数组 nums，和目标值 target，求出和为target的各种组合，可多次使用nums里的值
*/

#include <vector>

using namespace std;
class CombinationSum {
public:
	//采用字典树的方式在当前位置取值、或者下一个位置取值两个分支上递归

	void dfs(vector<int>& nums, int target, vector<vector<int>>& ans,vector<int> combination, int idx) {
		//往前取一位时，不能超过数组大小
		if (idx == nums.size()) {
			return;
		}

		if (target == 0) {
			//组合的总和满足target，作为一种答案
			ans.emplace_back(combination);
			return;
		}

		dfs(nums, target, ans, combination, idx+1);
		//取当前值
		int remind = target - nums[idx];
		if (remind >= 0) {
			combination.emplace_back(nums[idx]);
			dfs(nums, remind, ans, combination, idx);
			//
			combination.pop_back();
		}
	}

	vector<vector<int>> GetRes(vector<int> nums, int target) {
		vector<vector<int>> ans;
		//
		vector<int> combination;

		dfs(nums, target, ans, combination, 0);

		return ans;
	}
};