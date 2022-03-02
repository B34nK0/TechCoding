#pragma once

/*
leetCode 415 字符串相加
字符与'0' 相加减可得到对应的数值
 ‘1’ - ‘0’ = 1
 1 + ‘0’ = ‘1’
*/
#include <string>

using namespace std;
class AddStrings {
public:
	string AddTwoString(string& strA, string& strB) {
		if (strA.empty() || strB.empty()) {
			return strA.empty() ? strB : strA;
		}

		int add = 0;
		int i = strA.length() - 1;
		int j = strB.length() - 1;

		//结果
		string ans = "";
		//从字符串尾遍历数值位，或者有进位时
		while (i >= 0 || j >= 0 || add > 0) {
			//判断哪个字符串遍历结束了
			int a = i >= 0 ? strA[i] - '0' : 0;
			int b = j >= 0 ? strB[j] - '0' : 0;
			int result = a + b + add;
			//获取进位值
			add = result / 10;
			//当前数值位的值
			ans.push_back(result % 10 + '0');
			//
			i--;
			j--;
		}

		//反转存取的数值
		reverse(ans.begin(), ans.end());

		return ans;
	}
};