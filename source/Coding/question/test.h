#pragma once

#include <unordered_map>

using namespace std;
class test {
public:
	static unordered_map<int, int> testMap;

	static void TestMap() {
		testMap = {};
	}
};

unordered_map<int, int > test::testMap = {};
