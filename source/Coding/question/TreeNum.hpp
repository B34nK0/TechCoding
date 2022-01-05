/*
从数组中组合出三元组，三元组和为零，且每个三元组不可重复
*/

#include <vector>
#include <algorithm>

using namespace std;

class TreeNum {
public:
	static vector<vector<int>> FindTreeNum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
	
		vector<vector<int>> res;

		for (int i = 0; i < nums.size(); ++i) {
			//如果与前一个值重复，那么组合出来的内容即会有重复三元组的情况
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			//两个指针指向三元组的第二跟第三个值
			int lo = i + 1, hi = nums.size() - 1;
			//第二、三的值需要与第一值的反值相等，那么相加才会等于0
			int t = -nums[i];

			while (lo < hi) {
				if (nums[lo] + nums[hi] == t) {
					vector<int> tmp({ nums[i],nums[lo],nums[hi] });
					res.emplace_back(tmp);
					//跳过相同值
					while (lo < hi && nums[lo] == nums[lo + 1])++lo;
					while (lo < hi && nums[hi] == nums[hi - 1])--hi;
					++lo;
					--hi;
				}
				else if (t > nums[lo] + nums[hi]) ++lo;
				else --hi;
			}
		}

		return res;
	}
};