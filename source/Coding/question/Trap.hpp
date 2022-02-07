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
};