// 邪恶的69

#include<string>
#include<queue>
#include<deque>
using namespace std;

class Paired69 {
public:
	static string GetPaired69(string s) {
		if (s.empty()) {
			return "";
		}
		if (s == " ") {
			return s;
		}
		/*if (s == "69" || s == "6969" || s=="6699") {
			return s;
		}*/
		queue<char> cache;
		deque<char> result;
		for (auto c : s) {
			if (c == '6') {
				cache.push(c);
			}
			else {
				if (cache.empty()) {
					result.push_back(c);
					result.push_front('6');
				}
				else {
					char temp = cache.front();
					result.push_front(temp);
					result.push_back(c);
					cache.pop();
				}
			}
		}
		
		while (!cache.empty()) {
			char temp = cache.front();
			result.push_back(temp);
			result.push_back('9');
			cache.pop();
		}

		string strResult;
		while (!result.empty()) {
			char temp = result.front();
			result.pop_front();
			strResult.push_back(temp);
		}

		return strResult;
	}
};