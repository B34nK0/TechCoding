#include <list>
#include <unordered_map>

using namespace std;

class LruCache {
private :
	//pair->first 对应map的key
	//pair->second 对应map的value
	list<pair<int, int>> _values;

	unordered_map<int, list<pair<int,int>>::iterator> _container;

	int _capacity;

public:
	LruCache(int capacity) {
		_capacity = capacity;
	}

	int Get(int key) {
		auto value = _container.find(key);
		if (_container.end() == value) {
			return -1;
		}
		//将哈希表key指向的list节点迁移到链表的表头
		_values.splice(_values.begin(), _values, value->second);

		return value->second->second;
	}

	void Put(int key, int value) {
		auto oldValue = _container.find(key);
		if (_container.end() != oldValue) {
			//更新缓存数据
			oldValue->second->second = value;
			//将哈希表key指向的list节点迁移到链表的表头
			_values.splice(_values.begin(), _values, oldValue->second);
			return;
		}

		if (_container.size() == _capacity) {
			//获取链表尾节点，释放其位置放置新数据
			auto oldValue = _values.back();
			//删掉哈希表索引
			_container.erase(oldValue.first);
			//删除索引指向数据
			_values.pop_back();
		}

		_values.emplace_front(key, value);
		_container[key] = _values.begin();
	}
};