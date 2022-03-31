/*
leetCode 146LRU缓存
LRU也叫最近使用过Least Recently Used
常用于实现缓存淘汰机制，即预加载热数据

使用链表来存储键值对
1、放置数据时，如果已在缓存中，那么将数据节点更新到表头
2、数据不在缓存中时，如果容量不足，则将表尾数据淘汰，同时将数据节点放置表头
3、获取数据时，如果在缓存中，即将数据节点移动到表头
不在缓存时返回-1

使用unordered_map来记录key到链表节点pair的映射
*/

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
		//splice作用是用于接合两个链表
		//将value->second迭代器所指元素接合于_values.begin()所指位置之前
		_values.splice(_values.begin(), _values, value->second);
		//返回节点值
		return value->second->second;
	}

	void Put(int key, int value) {
		//判断缓存中是否存在数据
		auto oldValue = _container.find(key);
		if (_container.end() != oldValue) {
			//更新缓存数据
			oldValue->second->second = value;
			//将哈希表key指向的list节点迁移到链表的表头
			_values.splice(_values.begin(), _values, oldValue->second);
			return;
		}
		//缓存不命中时，判断容量是否足够
		if (_container.size() == _capacity) {
			//获取链表尾节点，释放其位置放置新数据
			auto oldValue = _values.back();
			//删掉哈希表索引
			_container.erase(oldValue.first);
			//删除索引指向数据
			_values.pop_back();
		}

		_values.emplace_front(key, value);
		//将kv在链表中的迭代器放到unordered_map中用于索引
		_container[key] = _values.begin();
	}
};