
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <map>
#include <deque>

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
	for (int i = 0; i < count; ++i) {
		//去重输出
		if (i != 0 && allNums[i] == allNums[i - 1]) {
			continue;
		}
		cout << allNums[i] << endl;
	}
}

/*
* 判断ip及掩码
*/
bool checkMask(string mask) {
	istringstream iss(mask);
	string seg;
	unsigned b = 0;
	while (getline(iss, seg, '.')) {
		b = (b << 8) + stoi(seg);
	}
	if (!b) return false;
	b = ~b + 1;
	if (b == 1) return false;
	if ((b & (b - 1)) == 0) return true;
	return false;
}

bool checkIp(string ip) {
	int j = 0;
	istringstream iss(ip);
	string seg;
	while (getline(iss, seg, '.'))
		if (++j > 4 || seg.empty() || stoi(seg) > 255)
			return false;
	return j == 4;
}

bool checkPrivate(string ip) {
	istringstream iss(ip);
	string seg;
	vector<int> v;
	while (getline(iss, seg, '.')) v.push_back(stoi(seg));
	if (v[0] == 10) return true;
	if (v[0] == 172 && (v[1] >= 16 && v[1] <= 31)) return true;
	if (v[0] == 192 && v[1] == 168) return true;
	return false;
}

static void HJ18() {
	cout << "HJ18" << endl;

	int errCount = 0, a = 0, b = 0, c = 0, d = 0, e = 0, privateCount = 0;

	string input;
	//获取每行数据
	while (cin >> input) {
		istringstream is(input);
		string add;
		vector<string> v;
		//通过istringstream
		while (getline(is, add, '~')) {
			v.push_back(add);
		}
		//如果子网掩码错误，即不处理ip
		string ip = v[0], mask = v[1];
		if (!checkMask(mask)) {
			errCount++;
			continue;
		}

		if (checkIp(ip)) {
			//检查是否私有
			if (checkPrivate(ip)) {
				privateCount++;
			}

			//对ip进行分类
			//获取ip的前八位值
			int first = stoi(ip.substr(0, ip.find_first_of('.')));
			if (first > 0 && first < 127) {
				a++;
			}
			else if (first > 127 && first < 192) {
				b++;
			}
			else if (first > 191 && first < 224) {
				c++;
			}
			else if (first > 223 && first < 240) {
				d++;
			}
			else if (first > 239 && first < 256) {
				e++;
			}
		}
		else {
			errCount++;
		}
	}

	cout << a << " " << b << " " << c << " " << d << " " << e << " " << errCount << " " << privateCount << endl;
}


/*
输出最新八个错误，如果有重复，统计次数
*/
static void HJ19() {
	cout << "HJ19" << endl;
	string str;
	map<string, int> result;

	deque<string>deq;
	while (getline(cin, str)) {
		//文件名
		str = str.substr(str.find_last_of('\\') + 1);
		int pos = str.find_last_of(' ');
		if (pos > 16) {
			str = str.substr(pos - 16);
		}

		if (result.find(str) == result.end()) {
			deq.push_back(str);
		}
		++result[str];
		if (deq.size() > 8) {
			deq.pop_front();
		}
	}
	for (auto x : deq) {
		cout << x << " " << result[x] << endl;
	}
}

/*
合唱队伍
输入n个学生
要求拿掉k个学生形成队伍
队伍身高中高向两边递减
求拿掉最少的k
*/
static void HJ24() {
	cout << "HJ24" << endl;
	int studentCount = 0;
	while (cin >> studentCount) {
		vector<int> studentHights(studentCount);
		for (auto& student : studentHights) {
			cin >> student;
		}

		//求每个位置的上升序列
		vector<int> indexL(studentCount);
		for (int i = 0; i < studentCount; ++i) {
			for (int j = 0; j < i; ++j) {
				if (studentHights[i] > studentHights[j]) {
					indexL[i] = max(indexL[i], indexL[j]);
				}
			}
			indexL[i] = indexL[i] + 1;
		}
		vector<int> indexR(studentCount);
		for (int i = studentCount - 1; i >= 0; --i) {
			for (int j = studentCount - 1; j > i; --j) {
				if (studentHights[i] > studentHights[j]) {
					indexR[i] = max(indexR[i], indexR[j]);
				}
			}
			indexR[i] = indexR[i] + 1;
		}

		int max = 0;
		for (int i = 0; i < studentCount; ++i) {
			int maxK = indexL[i] + indexR[i] - 1;
			max = maxK > max ? maxK: max;
		}

		cout << studentCount - max << endl;
	}
}

/*
0326 华为od
给定一个正整数数组，检查数组中是否存在满足规则的数字组合
规则： A = B + 2C

输入描述:

第一行输出数组的元素个数。
接下来一行输出所有数组元素，用空格隔开。
输出描述:

如果存在满足要求的数，在同一行里依次输出规则里A/B/C的取值，用空格隔开。
如果不存在，输出0。
*/
static void HJTest1() {
	cout << "HJTest1" << endl;

	int count = 0;
	//数组的个数
	cin >> count;

	vector<int> nums(count);
	//通过引用的方式输入数组，这里的个数应该与输入的count一致，不然会越界，不是题目考察范畴
	for (auto& num : nums) {
		cin >> num;
	}

	//暴力求解
	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < count; ++j) {
			for (int k = 0; k < count; ++k) {
				//不可重复使用数值，需要判断i!=j!=k
				if (i != j && j != k && nums[i] == nums[j] + 2 * nums[k]) {
					cout << nums[i] << ' ' << nums[j] << ' ' << nums[k];
					return ;
				}
			}
		}
	}

	cout << 0 << endl;
	return;
}