#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;
class GroupAnagrams {
public:
	static vector<vector<string>> convertAnagrams(vector<string>& arr) {
		unordered_map<string, vector<string>> strMap;

		for (auto& s : arr) {
			string tmp = s;
			//将字符串进行排序用于做key
			sort(tmp.begin(), tmp.begin());
			strMap[tmp].push_back(s);
		}

		vector<vector<string>> res;
		for (auto& itr : strMap) {
			res.push_back(itr.second);
		}

		return res;
	}
};