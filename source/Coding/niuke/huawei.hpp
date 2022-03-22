
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

//华为机试3 输入n个随机数，去除重复的数只保留一个，并升序返回
//第一行输入 表示n个随机数 其余行表示随机数值
// 3
// 2
// 2
// 1
// 输出 1， 2
static void HJ3() {
	cout << "HJ3" << endl;

	int count;
	cin >> count;
	vector<int> allNums(count);
	//连续输入随机数
	for (int i = 0; i < count; ++i) {
		cin >> allNums[i];
	}
	sort(allNums.begin(), allNums.end());
	for (int i = 0; 0 < count; ++i) {
		//去重输出
		if (i != 0 && allNums[i] == allNums[i - 1]) {
			continue;
		}
		cout << allNums[i] << endl;
	}
}