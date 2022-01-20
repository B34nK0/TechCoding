#pragma once

#include <vector>
#include <algorithm>
using namespace std;
/*
* leetCode 15
三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
*/

class ThreeSum {
public:
	static vector<vector<int>> Sum(vector<int> nums) {
		vector<vector<int>> ans;
		if (nums.size() < 3) {
			return ans;
		}
		//先排序解决重复的问题
		sort(nums.begin(), nums.end());
		int n = nums.size();
		//三重遍历的第一个元素
		for (int first = 0; first < n; ++first) {
			//特殊出来，如果第一个元素大于0，那么右面的值相加不可能等于0
			if (nums[first] > 0) {
				return ans;
			}
			//当前元素与前一个元素相同，那么找到的三元组就会有重复的情况
			if (first > 0 && nums[first] == nums[first-1]) {
				continue;
			}

			//第三个元素的位置
			int third = nums.size() - 1;

			int target = -nums[first];
			//遍历第二个元素，第二个元素应该在第三个元素的左侧
			for (int second = first + 1; second < n; ++second) {
				//如果第二个元素与前一个元素一样，那么说明会得到相同的三元组，所以跳过
				if (second > first + 1 && nums[second] == nums[second-1]) {
					continue;
				}
				//寻找第三个元素使二三元素和等于第一元素值的反值
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
			
				if (second == third) {
					break;
				}

				if (nums[second] + nums[third] == target) {
					ans.emplace_back(vector<int>{nums[first], nums[second], nums[third]});
				}
			}
		}
		return ans;
	}
};