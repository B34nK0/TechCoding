/*
leetCode 圆环上有10个点（0~9） ，可以顺时针或者逆时针行走一步。
输入n步，输出有多少种方法可以回到原点
输入2
输出2： 表示 0->1->0, 0->9->0

该问题与leetCode 70 爬楼梯方式:走n步到0的方案数=走n-1步到1的方案数+走n-1步到9的方案数。
*/
#include <vector>
using namespace std;

class BackToOrigin {
public:
	static int GetNums(int n) {
		//圆环数量
		int length = 10;
		vector<vector<int>> dp(n + 1, vector<int>(length, 0));
		dp[0][0] = 1;
		//
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < length; ++j) {
				//dp[i][j]表示从0出发，走i步到j的方案数
				dp[i][j] = dp[i - 1][(j - 1 + length) % length] + dp[i - 1][(j + 1) % length];
			}
		}

		return dp[n][0];
	}
};