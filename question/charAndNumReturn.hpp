#include <string>
#include <queue>
//
//给定一个包含连续字母、连续数字即空格的字符串
//实现字母按出现顺序而数字按小到大排在字母后

using namespace std;
class charAndNumReturn {
public :
	static string getCharAndNumReturn(string content) {
		priority_queue<char,vector<char>, greater<char>> numbers;
		string result;
		for (char s : content) {
			if (s == ' ') {
				continue;
			}
			if (s >= '0' && s <= '9') {
				numbers.push(s);
				continue;
			}
			result.push_back(s);
		}

		while (!numbers.empty()) {
			char i = numbers.top();
			result.push_back(i);
			numbers.pop();
		}

		return result;
	}
};