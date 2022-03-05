
/*
leetCode 76 最小覆盖子串

给定字符串s，t，求 s中覆盖t所有字符的最小子串
abaacbab  , abc  => acb
*/

#include <string>
#include <unordered_map>

using namespace std;
class MinWindow {
public:
	//记录t字符串每个字符需要的数量
	unordered_map<char, int> _t_count;
	//当前窗口中t字符的数量
	unordered_map<char, int> _w_count;

	//检测窗口内是否包含所有字符
	bool check() {
		//遍历t字符哈希表
		for (const auto& p : _t_count) {
			//检测窗口内某字符的数量小于t字符串里的字符的数量时 返回false
			if (_w_count[p.first] < p.second) {
				return false;
			}
		}
		return true;
	}

	string GetRes(string s, string t) {
		//记录t字符数量哈希表
		for (auto& c : t) {
			++_t_count[c];
		}

		//窗口的左右指针
		int l = 0, r = -1;

		//
		int len = INT_MAX, ansL = -1;

		//窗口还未到底
		while (r < int(s.size())) {
			//记录窗口内字符数量

			//当前字符是t字符需要的，往窗口记录
			if (_t_count.find(s[++r]) != _t_count.end()) {
				++_w_count[s[r]];
			}

			//如果窗口已包含所有字符 且 窗口大小有值，即右移
			while (check() && l <= r) {

				//获取当前窗口l的位置以及长度
				if (r - l + 1 < len) {
					len = r - l + 1;
					ansL = l;
				}
				//l左移的话需要去掉窗口里的字符数
				if (_t_count.find(s[l]) != _t_count.end()) {
					--_w_count[s[l]];
				}
				
				++l;
			}
		}

		return ansL >= 0 ? s.substr(ansL, len) : "";
	}
};