#include <vector>
#include <math.h>

using namespace std;

/*
* 买卖股票的最佳时机
*/
//给出股票的价格数组，找出最佳买卖点,得出收益
class FindStockBuySell {
public:
	//leetcode 121
	/*
	* 一次股票交易的最大收益
	*/
	static int FindResult(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}
		int result = 0;
		int minPrice = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			//当前位置与最小值的差即为收益
			result = max(result, prices[i] - minPrice);
			//记录产生的最小值作为买价
			minPrice = min(minPrice, prices[i]);
		}

		return result;
	}

	/*
	leetCode 122
	不能同时参与多笔交易
	*/
	//动态规划
	static int SumBuySell(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}

		int n = prices.size();
		int** dp = new int*[n];
		for (int i = 0; i < n; ++i) {
			dp[i] = new int[2];
		}
		//第0天
		//不持有股票时的收益
		dp[0][0] = 0;
		//持有股票时的收益
		dp[0][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			//当前点位时
			// 
			// 不持有时的收益  
			// 比较 前一个点位不持有收益  前一点位持有时当前点位卖出（+price）收益
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			//持有时的收益
			// 比较 前一个点位持有收益  前一点位不持有时当前点位买入（-price）收益
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		//不持有时的收益明显大于持有时的收益
		return dp[n-1][0];
	}

	//贪心算法
	static int SumBuySell2(vector<int> prices) {
		if (prices.empty()) {
			return 0;
		}

		int result = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > prices[i - 1]) {
				result += (prices[i] - prices[i - 1]);
			}
		}

		return result;
	}

	//进阶，最多两次交易，计算最大收益
	static int MaxProfit(vector<int>& prices) {
		int min_so_far = numeric_limits<int>::max();
		vector<int> profit_first_trade(prices.size(), 0);
		int max_profit = 0;

		//顺排
		for (int i = 0; i < prices.size(); ++i) {
			//当前位置上的最小价格可以当买价
			min_so_far = min(min_so_far, prices[i]);
			//当前位置上的最大收益=当前价-之前的最低价
			max_profit = max(max_profit, prices[i] - min_so_far);
			//存储每个位置产生的最高收益
			profit_first_trade[i] = max_profit;
		}

		int max_so_far = numeric_limits<int>::min();

		//倒排
		for (int i = prices.size() - 1; i > 0; --i) {
			//当前位置上的最大价格作为卖价
			max_so_far = max(prices[i], max_so_far);
			//计算当前位置与当前位置之前产生交易的最大收益和
			max_profit = max(max_profit, max_so_far - prices[i] + profit_first_trade[i - 1]);
		}

		return max_profit;
	}
};