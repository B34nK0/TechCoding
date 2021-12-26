// 将数字放到字符串后边
#include <string>
#include <queue>

using namespace std;
class CharAndNumReturn {
public :
	static string GetCharAndNumReturn(string content) {
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