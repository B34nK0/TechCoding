#pragma once

/// <summary>
/// leetCode 42接雨水
/// 
/// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] 表示的高度图
/// </summary>
/// 

#include <vector>

using namespace std;

class Trap {
public:
	static int GetTrapResult(vector<int>& height) {
		//采用左右双指针方式，
		int* leftIndex = &height[0], *rightIndex = &height[height.size()-1];
		int leftMaxHeight = *leftIndex, rightMaxHeight = *rightIndex;

		int ans = 0;
		//当两指针相遇时已经不能形成低洼了
		while (leftIndex != rightIndex) {
			if (*leftIndex >= leftMaxHeight) {
				leftMaxHeight = *leftIndex;
			}
			else {
				ans += (leftMaxHeight - *leftIndex);
			}


			if (*rightIndex >= rightMaxHeight) {
				rightMaxHeight = *rightIndex;
			}
			else {
				ans += (rightMaxHeight - *rightIndex);
			}

			if (*leftIndex > *rightIndex) {
				rightIndex--;
			}
			else {
				leftIndex++;
			}
		}

		return ans;
	}

	//采用遍历记录每个位置的左右最高值
	static int GetTrapResult2(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		vector<int> leftMax(n);
		leftMax[0] = nums[0];
		for (int i = 1; i < n; ++i) {
			//左边记录的值与当前高度比
			leftMax[i] = max(leftMax[i - 1], nums[i]);
		}

		//从右往左记录右边最大高度
		vector<int> rightMax(n);
		rightMax[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			//右边记录的值与当前高度比
			rightMax[i] = max(rightMax[i + 1], nums[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			//左右高度值的最小值减去当前高度
			ans += min(leftMax[i], rightMax[i]) - nums[i];
		}
		return ans;
	}
};