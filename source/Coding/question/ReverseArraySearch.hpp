#pragma once

/// <summary>
/// leetCode 33 搜索旋转排序数组目标值的下标
/// [4,5,6,7,0,1,2] target = 0, 下标为4,
/// 不存在即返回-1
/// </summary>

#include <vector>

using namespace std;

class ReverseArraySearch {
public:
	int Search(vector<int>& nums, int target) {
		if (nums.empty()) return -1;

		if (nums.size() == 1) {
			return target == nums[0] ? 0 : -1;
		}

		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (target == nums[mid]) return mid;

			//有序
			if (nums[0] <= nums[mid]) {
				//目标值在mid左边
				if (nums[0] <= target && target < nums[mid]) {
					right = mid - 1;
				} else{
					left = mid + 1;
				}
			}
			else {
				//目标值在mid右边
				if (nums[mid] < target && target <= nums[nums.size() - 1]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}

		return -1;
	}
};