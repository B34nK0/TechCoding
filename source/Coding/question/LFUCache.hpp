/*
leetCode 460 LFU 缓存
最少使用缓存采用 set来做频率排序，set背后为红黑树
再通过map哈希表来记录key-value
为实现set排序，需要定义节点的>操作符
*/

#include <unordered_map>
#include <set>

using namespace std;

struct LFUNode {

	int _key;
	int _value;
	int _time;
	int _count;


	LFUNode(int key,int value,int time,int count):_key(key), _value(value), _time(time), _count(count) {

	}

	bool operator < (const LFUNode& node) const {
		return _count == node._count ? _time < node._time : _count < node._count;
	}
};

class LFUCache {
	unordered_map<int, LFUNode> _keyTable;
	set<LFUNode> _data;
	int _capacity;
	int _time;
public:
	LFUCache(int capacity):_capacity(capacity) {
		_time = 0;
		_keyTable.clear();
		_data.clear();
	}

	void Put(int key, int value) {
		if (_capacity == 0) return;
		auto itr = _keyTable.find(key);
		if (itr == _keyTable.end()) {
			//如果已经达到容量时，需要删除最少使用的节点，用于放置新节点
			if (_data.size() == _capacity) {
				//删除最少使用的节点
				_keyTable.erase(_data.begin()->_key);
				_data.erase(_data.begin());
			}
			else {
				LFUNode data(key, value, 0, 1);
				_keyTable.insert(make_pair(key, data));
				_data.insert(data);
			}
		} else {
			LFUNode data = itr->second;
			//从红黑树删除旧节点
			_data.erase(data);
			//更新新节点频率
			data._count++;
			data._time++;
			//放回红黑树
			_data.insert(data);
			itr->second = data;
		}
	}

	int Get(int key) {
		if (_capacity == 0) return -1;
		auto itr = _keyTable.find(key);
		if (itr == _keyTable.end()) {
			return -1;
		}
		LFUNode data = itr->second;
		//从红黑树删除旧节点
		_data.erase(data);
		//更新新节点频率
		data._count++;
		data._time++;
		//放回红黑树
		_data.insert(data);
		itr->second = data;
		return data._value;
	}
};
