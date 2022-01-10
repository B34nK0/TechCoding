#pragma once
/*
先用hashmap存储，用来记录字符的次数
再对字符按出现的频率进行排序
*/

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

struct Node{
	char c;
	int freq;
	Node(char ch, int iFreq) :c(ch), freq(iFreq) {

	}
};

struct compare_func {
	inline bool operator() (const Node& n1, const Node& n2) {
		return n1.freq > n2.freq;
	}
};

class FrequencySort {
public:
	string Sort(string s) {
		unordered_map<char, int> cmap;
		for (auto& ch : s) {
			cmap[ch]++;
		}

		vector<Node> chfreqs;
		for (auto& elem : cmap) {
			chfreqs.push_back(Node(elem.first, elem.second));
		}

		sort(chfreqs.begin(), chfreqs.end(), compare_func());
		stringstream ss;
		for (auto& node : chfreqs) {
			for (int i = 0; i < node.freq; ++i) {
				ss << node.c;
			}
		}

		return ss.str();
	}
};