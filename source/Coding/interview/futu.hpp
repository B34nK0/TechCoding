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
如果是偶尔慢，那么可能是网络抖动（应用表现或者远程）、可能是redo满了，脏页需要进行刷盘，或者磁盘满了导致刷盘失败lock住了（测试环境遇到）
如果是长时间慢，那是sql语句问题，是否建索引，where是否采用了函数，辅助索引不如走主键索引全表查询

3、索引命中后还很慢


4、建索引之后还是无法命中


5、mysql为什么需要一个自增主键，应该是限定在Innodb下。
InnoDB引擎底层的数据结构是B+树，索引正式采用B+树来实现快速搜索（logN），一个表有多少个索引就会有多少颗树。
mysql中的数据按顺序存储在叶子节点上。

保持顺序的目的：
提高范围查询效率、增加排序效率、提高扫表能力。

mysql底层以数据页（16k，可以自定义）为单位进行存储，如果一个页存满了自然要申请一个新的数据页来存储数据。
当主键是自增时，写满一个页直接申请一个新的页接着写
如果非自增，为了确保索引有序，mysql需要将插入的数据放到合适的位置（随机写），并且把上一页的部分数据迁移到新的数据页，这会造成页分裂。

扩展：
如果没有自定义主键时，mysql会采用非空唯一索引来当主键，而没有非空唯一索引时虚拟出6字节的列作为隐藏主键。

数据结构

6、map hash_map 区别
map采用红黑树作为底层结构，其查找效率为O(logN)
hash_map以hashtable为底层结构，时间复杂度O(1)

map区别于hash_map在于 红黑树操作元素后会重排，始终保持有序


7、解决hash冲突方法
线性探测（linear probing）、二次探测（quadratic probing）、开链（separate chaining）

线性探测：循序寻找，假设表格足够大，当找到位置有元素时，找下一个可用空间（环式）。获取元素时同理，找到元素不为空时判断key是否为查找的key，不是则继续往下找。
当删除元素时，采用惰性删除方式，先标记元素，等到rehash调整时再删除。
缺点在于如果每个元素不够独立，即合理下标位置被占用时会一直找到合适的位置

二次探测：

开链法：在每个表格元素中维护一个list


消息队列

8、rabbitmq如何保证消息不丢失

9、幂等性

10、生产方保证消息不丢失

*/

//二面

/*
* leetCode 459 重复的子字符串
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

可以采用KMP模式匹配： checkKMP(s+s, s),kmp较难，采用第二种思路
字符串 s，及其 长度n，如果由某个子串 s' 组成，那么 s'的长度n'为n的整除数
s'前缀与s一样，可以匹配s[i] = s[i-n'],递增i的值
*/
class RepeatedSubstringPattern {
public:
	static bool CheckIsRepeated(std::string str) {
		if (str.empty()) {
			return false;
		}

		//
		int n = str.size();
		//如果由子串组成，那么至少是2个
		for (int i = 1; i * 2 <= n; ++i) {

			//遍历i到n，只在i位置与字符串长度形成整数倍时才停止
			if (n % i == 0) {
				bool match = true;
				for (int j = i; j < n; ++j) {
					if (str[j] != str[j - i]) {
						match = false;
						break;
					}
				}

				if (match) {
					return true;
				}
			}

		}
	}
};


/*
*
函数x，50%概率返回0跟1
实现函数y，等概率返回0到9的数
*/
class RandY {
public:

	static int RandX() {
		return rand() % 2;
	}

	static int GetRandNum() {

		int num = 0;
		do {
			num = RandX() << 3;
			num += RandX() << 2;
			num += RandX() << 1;
			num += RandX();
		} while (num > 9);
		
		return num;
	}
};