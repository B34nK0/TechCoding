#pragma once

#include <string>
#include <stack>

using namespace std;
class MatchParentTheses {
public:
	static bool IsOpen(char c) {
		return c == '(' || c == '[' || c == '{';
	}

	static bool IsClose(char c) {
		return c == ')' || c == ']' || c == '}';
	}

	static char GetClose(char c) {
		if (c == '(') return ')';
		else if (c == '[') return ']';
		else if (c == '{') return '}';
	}

	static bool IsValid(string s) {
		stack<char> stk;
		for (auto c : s) {
			if (IsOpen(c)) {
				stk.push(c);
			}
			else {
				if (stk.empty()) return false;
				if (GetClose(stk.top()) != c) return false;
				stk.pop();
			}
		}

		return stk.empty();
	}
};