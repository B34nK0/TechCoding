#pragma once

#include <vector>
#include <unordered_set>
/*
* leetCode 3 
获取字符串中最长不重复字符子串的长度
输入: s = "abcabcbb"
输出: 3
*/

using namespace std;
class LengthOfLongestSubstring {
public:
	static int GetMaxLength(string s) {
		//哈希表，用于记录字符出现的位置
		unordered_set<char> occ;
		//遍历字符串
		int ri=0;
		int maxLength = 0;

		for (int i = 0; i < s.length(); ++i) {
			
			if (i != 0) {
				// 左指针向右移动一格，移除一个字符
				occ.erase(s[i-1]);
			}

			//移动右指针，如果hash表没有该字符，那么将其放到hash表
			//有该字符的话，表明当前字符与窗口内的子串存在相同字符，需要跳出循环计算窗口子串的长度
			while (ri < s.length() && !occ.count(s[ri])) {
				occ.insert(s[ri]);
				++ri;
			}
			//ri索引的字符与hash表重复的字符，那么计算当前的最大字符串长度
			maxLength = max(maxLength, ri - i);		
		}


		return maxLength;
	}
};