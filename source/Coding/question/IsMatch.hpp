/*
leetCode10 正则匹配

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

*/

#include <string>
#include <vector>

using namespace std;
class IsMatch {
public:
	bool CheckIsMatch(string s, string p) {
		int m = s.length();
		int n = p.length();

		vector<vector<int>> dp(m+1, vector<int>(n+1));
		dp[0][0] = 1;
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j-1] != '*') {
					if (i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
						dp[i][j] = dp[i - 1][j - 1];
					}
				}
				else {
					if (j >= 2 && i >= 1 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
						dp[i][j] = dp[i - 1][j];
					}
					if (j >= 2) {
						dp[i][j] |= dp[i][j - 2];
					}
				}
			}
		}

		return dp[m][n];
	}
};