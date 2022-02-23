#pragma once


/// <summary>
/// leetCode 1 求两数之和为目标值的下标
/// </summary>
/// 
#include <vector>
#include <unordered_map>
using namespace std;
class TwoSum {
public:

	static vector<int> GetRes(vector<int>& nums, int target) {
		//通过map来记录数在数组的下标
		unordered_map<int, int> numIndex;

		for (int i = 0; i < nums.size(); ++i) {
			//目标值 - 当前数值 = 剩余值
			int gap = target - nums[i];
			//查找剩余值是否已记录
			auto index = numIndex.find(gap);
			//找到两数和为target
			if (index != numIndex.end()) {
				return { index->second, i };
			}

			numIndex[nums[i]] = i;
		}

		return {};
	}
};
