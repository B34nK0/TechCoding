/*
leetCode 162 寻找峰值

nums[1,2,3,1] 输出 2
nums[2] = 3 3 
*/

#include <vector>

using namespace std;
class FindPeakElement {
public:
	static int GetRes(vector<long long>& nums) {
		int count = nums.size()-1;
		//采用二分法查找
		int left = 0, right = count;

		int ans = -1;
		int midValue = 0, midLeftValue = LONG_MIN, midRightValue = LONG_MIN;

		while (left <= right) {
			int mid = (left + right) >> 1;

			//获取数组的值,用于处理 注意mid-1为-1， mid+1为 size(), 会造成溢出
			midValue = nums[mid];
			if (mid - 1 >= 0) {
				midLeftValue = nums[mid - 1];
			}
			if (mid + 1 <= count) {
				midRightValue = nums[mid + 1];
			}
			if (midValue > midLeftValue && midValue > midRightValue) {
				ans = mid;
				break;
			}

			if (midLeftValue >= midValue) {
				right = mid-1;
			}
			else {
				left = mid+1;
			}
		}

		return ans;
	}
};