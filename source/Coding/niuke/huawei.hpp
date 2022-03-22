
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//华为机试1 判断最后一个字符串的长度
static int HJ1() {
	cout << "HJ1" << endl;

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

static char toLower(char c) {
	if (c >= 'A' && c <= 'Z') {
		c = c - 'A' + 'a';
	}
	return c;
}

//华为机试2 输入一串字符串后，输入字符，获取字符在字符串中出现的次数
static int HJ2() {
	cout << "HJ2" << endl;

	unordered_map<char, int> mp;
	char c;
	while ((c = getchar()) != '\n') {
		c = toLower(c);
		mp[c]++;
	}

	char target;
	cin >> target;
	target = toLower(target);
	cout << mp[target] << endl;
	return mp[target];
}