/*
leetCode 24 两两交换链表中的节点

富途一面
*/

#include <string>

#include "CommonStruct.h"
class SwapPairs {
public:
	ListNode* TestSwapPairs(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}

		//制造空节点，用于返回
		ListNode* pre = new ListNode();
		//指向当前头结点
		pre->next = head;
		//0->1->2->
		ListNode* tmp = pre;

		//两两节点交换
		//1->2
		while (tmp->next != nullptr && tmp->next->next != nullptr) {
			//1
			ListNode* first = tmp->next;
			//2
			ListNode* second = tmp->next->next;
			//0->2
			tmp->next = second;
			//1->3
			first->next = second->next;
			//2->1
			second->next = first;
			//cur = 3
			tmp = first->next;
		}

		return pre->next;
	}
};

//压缩字符串空格并返回空格数量
class DelStringSpace {
public:
	int ReturnSpaceCount(std::string& content) {

		if (content.empty()) {
			return 0;
		}

		int count = 0;

		int begin = 0;
		for (int i = 0; i < content.length(); ++i) {
			if (content[i] == ' ') {
				count++;
				begin = i;
			}
			else if (begin != i) {
				content[begin] = content[i];
				begin++;
			}
		}

		int remind = content.length() - count;
		//通过resize自动裁减数据
		content.resize(remind);

		return count;
	}
};

/*
mysql

统计

1、where\having 的区别
where 是一个约束声明，在查询数据库的结果返回之前对数据库中的查询结果进行约束
having 是一个过滤声明，在查询结果之后对数据进行筛选，即在结果返回之后起作用，having之后可以使用聚合函数，多作用于组查询 group by，
比如统计选修了三门以上学生
select Sno from dbsc group by Sno having count(*)>3;

2、sql执行耗时可能比较长的原因，怎么优化


3、索引命中后还很慢


4、建索引之后还是无法命中


5、mysql为什么需要一个主键



数据结构

6、hashmap 散列表

7、解决hash冲突方法
rehash、



消息队列

8、rabbitmq如何保证消息不丢失

9、幂等性

10、生产方保证消息不丢失

*/