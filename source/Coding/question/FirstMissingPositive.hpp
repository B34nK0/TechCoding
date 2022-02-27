#pragma once

/// <summary>
/// leetCode 41缺失的第一个正整数
/// 从一个未排序的整数数组nums，找出其中没有出现的最小正整数
/// 如： [1,2,0] -> 3
/// [3,4,-1,1] -> 2
/// 
/// </summary>
/// 
/// 
#include <vector>
#include <algorithm>
using namespace std;

class FirstMissingPositive {
public:

	static int GetNum(vector<int>& nums) {
		//正整数为1~n的值
		int n = nums.size();
		//先遍历，将数组值置换到应在的位置
		for (int i = 0; i < n; ++i) {
			//持续对nums[i]进行判断其值是否为i+1，如果不是，那么将其置换到nums[i-1]的位置
			while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		//再次遍历数组，寻找与下标不符合的元素，即缺失的值为下标i+1
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};