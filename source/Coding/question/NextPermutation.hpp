#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class NextPermutation {
public:
	static void sortNextPermutation(vector<int>& nums) {
		int i = 0;
		//查找左边较小值
		for (i = nums.size() - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) break;
		}

		if (i == 0) {
			sort(nums.begin(), nums.end());
			return;
		}

		int j = 0;
		//查找右边较大值(大于获取的左边较小值)
		for (j = nums.size() - 1; j > 0; --j) {
			if (nums[j] > nums[i - 1]) break;
		}
		//交换左右较小值
		swap(nums[i - 1], nums[j]);

		//对右边进行排序，即为当前排序的下一个排序（大于当前排序）
		sort(nums.begin() + i, nums.end());
	}

	static void sortNextPermutation2(vector<int>& nums) {
		//查找降序的[i-1]
		int i = 0;
		for (i = nums.size() - 1; i > 0; --i) {
			if (nums[i] > nums[i - 1]) break;
		}

		//为0说明为升序，直接排序即可
		if (i != 0) {
			//有降序的，获取其右边较小的值进行交换
			int j = 0;
			for (j = nums.size() - 1; j > 0; --j) {
				if (nums[j] > nums[i - 1]) break;
			}
			swap(nums[i - 1], nums[j]);
		}

		sort(nums.begin() + i, nums.end());
	}
};