
/*
leetCode 322 零钱兑换
coins数组表示硬币的金额，amount表示目标金额
求出金额和为amount的最少个硬币数
[1,2,5]  amount = 11
求出3，表示 5 + 5 + 1。 假设硬币数无限
*/
#include <vector>
using namespace std;

class CoinChange {
public:
	int GetRes(vector<int>& coins, int amount) {
		int max = amount + 1;
		//记录每个解的最小硬币数
		vector<int> dp(amount+1, max);
		dp[0] = 0;
		//求出1~amount金额的需要最少硬币数
		//当前硬币金额idx, amount的最少硬币数等于 dp[amount-idx] + 1;
		//idx金额又可划分为求 idx的最少硬币数
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < coins.size(); ++j) {
				//硬币金额少于amount时才有组合
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i-coins[j]]+1);
				}
			}
		}

		return dp[amount] > amount ? -1 : dp[amount];
	}
};