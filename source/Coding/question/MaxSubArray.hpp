/*
* leetCode 53 最大子数组和
* 
* 给定一个数组nums，求出最大子序的和
* 
* -2,1,-3,4,-1,2,1,-5,4
* 
* 最大子序 4,-1,2,1 和为 6
*/

#include <vector>
using namespace std;

class MaxSubArray {
public:

	/*
	方法一：动态规划
	*/
	int GetMaximum(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int ans = nums[0];
		int pre = 0;
		//遍历每个元素，当前元素的子序合等于前序合加上当前值
		for (auto& num : nums) {
			//如果前子序合为负的，那么应该以当前值重新作为新的子序
			pre = max(pre + num, num);
			ans = max(ans, pre);
		}
		return ans;
	}

	/*
	方法二：分治法
	*/
	//以中点m划分 [l,r]数组为左右区间
	struct Status {
		//lsum 最大左子段和
		//rsum 最大右子段和
		//msum 区间最大子段和
		//isum 区间和
		int lSum, rSum, mSum, iSum;

		Status(int lSum, int rSum, int mSum, int iSum) {
			this->lSum = lSum;
			this->rSum = rSum;
			this->mSum = mSum;
			this->iSum = iSum;
		}
	};


	Status pushUp(Status l, Status r) {
		//区间和 等于左右子区间和 的总和
		int iSum = l.iSum + r.iSum;
		//最大序列横跨右区间的一部分
		//区间的最大左字段和 等于 max(左区间的最大左子段和，左区间的区间和+右区间的最大左字段和)
		int lSum = max(l.lSum, l.iSum + r.lSum);
		//最大序列横跨左区间的一部分
		//区间的最大右字段和 等于 max(右区间最大右字段和， 右区间和+左区间的最大右字段和)
		int rSum = max(r.rSum, r.iSum + l.rSum);
		//最大字段和 横跨两个区间
		//最大字段和 = max( max(左区间最大子段和， 右区间最大子段和) ,  左右区间的最大字段和 )
		int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
		return Status(lSum, rSum, mSum, iSum);
	};


	Status get(vector<int>& nums, int l, int r) {
		if (l == r) {
			return Status{ nums[l], nums[l], nums[l], nums[l] };
		}
		//右移一位相当于/2
		int m = (l + r) >> 1;
		//分别求出两个区间的最大子区间和等信息
		Status left = get(nums, l, m);
		Status right = get(nums, m + 1, r);
		return pushUp(left, right);
	}

	int GetRes(vector<int>& nums) {
		if (nums.empty()) return 0;

		return get(nums, 0, nums.size()-1).mSum;
	}
};