#pragma once
#include <vector>
#include <time.h>


/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
*/

using namespace std;
class FindKthLargest {
public:
	int quickSelect(vector<int>& nums, int left, int right, int k) {
		//查找轴值的位置
		int kindex = findKindex(nums, left, right);
		if (kindex == k) {
			return nums[kindex];
		}
		//使用快排确认轴值跟k的关系，如果轴值在当前数组的位置小于k的值，说明第k大的值在轴值右边
	//如果位置大于k值，说明第k大的值在轴值左边
		return kindex < k ? quickSelect(nums, kindex + 1, right, k) : quickSelect(nums, left, kindex - 1, k);
	}

	int partition_select_index(vector<int>& nums, int left, int right) {
		//当前轴值
		int pivot = nums[right];

		int i = left;
		for (int j = left; j < right; ++j) {
			if (nums[j] <= pivot) {
				std::swap(nums[i], nums[j]);
				i = i + 1;
			}
		}
		std::swap(nums[i], nums[right]);
		return i;
	}

	int findKindex(vector<int>& nums, int left, int right) {
		int index = rand() % (right - left + 1) + left;
		swap(nums[index], nums[right]);
		return partition_select_index(nums, left, right);
	}

	int FindKthLargestNum(vector<int>& nums, int k) {
	
		srand((unsigned int)time(NULL));
		return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
	}
};