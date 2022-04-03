
/*
leetCode 8 字符串转换整数 atoi

去掉字符串前后空格，有'+ -'表示正负值，没有时默认为正值
读到非数字字符时结束
范围在-2^31 ~ 2^31-1

采用有限状态机dfa进行解决
*/

#include <string>
#include <ctype.h> //引入isspace\isdigit判断是否为空格还是数字
#include <unordered_map>
#include <vector>
using namespace std;

class Automaton {
private:
	string state = "start";//状态机初始状态
	//某个状态下对应的后续状态
	unordered_map < string, vector<string>> stateMap = {
		{"start",{"start", "signed", "in_number", "end"}},
		{"signed", {"end", "end", "in_number", "end"}},
		{"in_number", {"end", "end","in_number", "end"}},
		{"end", {"end", "end", "end", "end"}}
	};

	//对应状态机表
	int getNextState(char c) {
		if (isspace(c)) return 0;
		else if (c == '+' || c == '-') return 1;
		else if (isdigit(c)) return 2;
		return 3;
	}

public:
	int sign = 1;//默认正值
	long long ans = 0; //解析出来的值

	void Parse(char c) {
		state = stateMap[state][getNextState(c)];
		if (state == "in_number") {
			ans = ans * 10 + c - '0';
			//注意ans的范围
			//-1 * INI_MIN会超过INT，所以需要long long存储
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, (long long)-1*INT_MIN);
		}
		else if (state == "signed") {
			sign = c == '+' ? 1 : -1;
		}
	}

	int GetNumber() {
		return sign * ans;
	}
};


class MyAtoi {
public:
	int AtoiConvert(string str) {
		Automaton automaton;
		for (char c : str) {
			automaton.Parse(c);
		}
		return automaton.GetNumber();
	}
};