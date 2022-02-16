#pragma once
/// <summary>
/// leetCode 300 最长递增子序列
/// 
/// [0,3,1,6,2,2,7] 最长递增子序列为 [0,1,2,7]
/// [0,1,0,3,2,3] => [0,1,2,3]
/// </summary>
/// 
#include<vector>
#include<algorithm>

using namespace std;

class LengthOfLIS {
public:
	static int GetLengthOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		vector<int> dp(nums.size(), 0);
		//遍历节点
		for (int i = 0; i < nums.size(); ++i) {
			dp[i] = 1;
			//从0开始到当前节点最大的升序长度
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		//判断所有节点中最长序列的节点
		return* max_element(dp.begin(), dp.end());
	}

	//采用贪心算法 + 二分查找
	static int GetLengthOfLIS2(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            }
            else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                //二分查找当前节点值在已查找到值的位置
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
	}
};