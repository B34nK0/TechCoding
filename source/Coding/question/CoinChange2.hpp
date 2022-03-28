/*
leetCode 518 零钱兑换2
给一个整数数组coins表示不同面额的硬币，另给一个整数amount 表示总金额
求可凑成总金额的硬币组合数
*/

#include <vector>
using namespace std;

class CoinChange2 {
public:
	int GetRes(int amount, vector<int>& coins) {
		//记录0到amount的总金额的硬币组合数
		vector<int> dp(amount+1, 0);
		//当总金额为0时，不取任何硬币，因此只有一种组合
		dp[0] = 1;
		//遍历硬币面额
		for (auto& coin : coins) {
			//从coin面额到amount金额
			for (int i = coin; i <= amount; ++i) {
				//金额i的组合数 = 由i金额减去coin面额的组合数贡献
				dp[i] += dp[i - coin];
			}
		}

		return dp[amount];
	}
};