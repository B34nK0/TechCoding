//华为机试1 判断最后一个字符串的长度

#include <iostream>
#include <string>
using namespace std;

static int HJ1() {
	string str;
	getline(cin, str);

	int length = str.length();
	int tmp = -1;
	for (int i = 0; i < length; ++i) {
		if (str[i] == ' ') {
			//记录新字符串的起始位置
			tmp = i;
		}
	}

	//字符串长度 - 字符串起始前一个位置时 需要再减一
	return length - tmp - 1;
}