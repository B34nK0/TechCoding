
/*
* leetCode 322
coins数组表示硬币的金额，amount表示目标金额
求出金额和为amount的最少个硬币数

采用动态规划的方式

面试官的要求：先讲出思路

{1, 2, 5, 7} target = 14
当金额为14时，targetNums[14-7]+1 = 2
targetNums[7-7]+1 = 1


[1,2,5]  target = 11
求出3，表示 5 + 5 + 1

target = 11时
targetNums[11-6]+1 = 3

target = 6时
targetNums[6-5] + 1 = 2

target = 1时
targetNums[1-1]+1 = 1
*/

#include <vector>
class solution {
public:
	int GetCoinsNums(std::vector<int> coins, int target) {
		//每个金额所需要的最少硬币数
		std::vector<int> targetNums(target + 1, target);
		//金额为0时最少数为0
		targetNums[0] = 0;
		//2
		for (int i = 1; i <= target; ++i) {
			//1, 2
			for (int j = 0; j < coins.size(); ++j) {
				//1
				if (coins[j] <= i) {
					//目标金额减去当前硬币金额
					targetNums[i] = std::min(targetNums[i], targetNums[i-coins[j]] + 1);
				}
			}
		}

		return targetNums[target] > target ? -1 : targetNums[target];
	}
};

/*

限流算法：

漏桶算法（漏斗）、令牌桶算法、计数器算法

漏桶算法：
1、固定容量的桶
2、按照固定的速率流出请求，不支持并发


令牌桶算法：
是漏桶算法的补充
1、以一定速率生成令牌放到桶里给消费
2、大于桶容量时，生成的令牌可以丢弃
3、当请求来时，可以获取桶内的令牌进行消费，如果令牌不够时可等待或者拒绝请求

区别于漏桶，令牌桶支持并发，只有能获取到令牌即请求可以通过

计数器算法：
1、设置一定时间内只能通过一定数量的请求
*/
#include <time.h>
class LeakBucketLimiter {
	//流出速率，每秒2个请求 
	int _rate;
	//容量
	int _capacity;
	//剩余的水量
	int _water;
	//最新一次请求时间
	time_t _lastRequestTime;
public:
	LeakBucketLimiter(int rate, int capacity, int water) {
		_rate = rate;
		_capacity = capacity;
		_water = water;
		time(&_lastRequestTime);
	}

	bool IsRateLimiterOK() {
		//桶为空时（容量跟请求数默认不能为0），加水，允许请求
		if (_water == 0) {
			_water++;
			return false;
		}

		//执行漏水
		time_t timestamp;
		time(&timestamp);
		//可请求数量，固定速率即每秒只能执行两个请求，
		int waterLeaked = (timestamp - _lastRequestTime) / 1000 * _rate;
		//不超过1秒时,waterLeaked为0
		int waterLeft = _water - waterLeaked;
		_water = std::max(0, waterLeft);
		//更新请求时间
		_lastRequestTime = timestamp;


		//还可以加水，允许请求
		if (_water < _capacity) {
			_water++;
			return true;
		}
		//超过容量，限流
		return false;
	}
};
class TokenBucketLimiter {
	//产生令牌效率
	int _rate;
	//容量
	int _capacity;
	//当前令牌数
	int _token;
	//最新一次请求时间
	time_t _lastRequestTime;
public:
	TokenBucketLimiter(int rate, int capacity) {
		_rate = rate;
		_capacity = capacity;
		_token = 0;
		time(&_lastRequestTime);
	}

	bool IsRateLimiterOK() {
		//当前产生的令牌数
		time_t now;
		time(&now);
		int produceToken = (now - _lastRequestTime) / 1000 * _rate;
		//
		int allToken = produceToken + _token;
		//只允许不超过限制容量的请求令牌数
		_token = std::min(_capacity, allToken);

		//消耗一次令牌
		if (_token > 0) {
			_token--;
			time(&_lastRequestTime);
			return true;
		}

		return false;
	}
};
/*
redis

redis为什么性能优异？

1、内存数据库。Redis的键值操作是基于内存的，内存的访问速度很快。
2、高效的底层数据结构。Redis底层会用到压缩列表、跳表、哈希表等数据结构。
3、高性能IO模型。Redis使用基于多路复用的高性能IO模型。

其单线程模式在于事件分发器采用单线程，而底层采用Reactor模式处理网络IO

什么时候用ziplist、skiplist？
1、当数据较少时，sorted set是由一个ziplist来实现的。
2、当数据多的时候，sorted set是由一个叫zset的数据结构来实现的，这个zset包含一个dict + 一个skiplist。
dict用来查询数据到分数(score)的对应关系，而skiplist用来根据分数查询数据（可能是范围查找）。

skiplist支持平均O(logN)、最坏O(N)复杂度的节点查找

hash结构的扩缩容？
redis的字典采用两个hashtale来存储数据，ht[0] ht[1],一般情况下 只使用ht[0], ht[1]用于rehash用
rehash过程采用渐进式方式，这是因为rehash过程中服务是不可用的，如果一次性rehash的话，数据量大，会导致长时间不可用
redis采用在键值增删改操作时，如果当前正在rehash状态，那么新增的值会直接操作到ht[1]，如果是查找的话，会先查找ht[0],
当ht[0]的键值均搬到ht[1]后，释放ht[0]，将ht[1]设置为ht[0]，并在ht[1]重新创建一个hashtable

雪花算法在k8s部署环境下如何保证唯一性？



付款流程第三方超时

分布式raft协议实现组件仓库的数据一致性

高可用跟一致性

*/

/*
mysql

mvcc机制？多版本并发控制
通过保存某个时间点的数据快照来实现并发控制，即保存数据的历史版本，读取数据时不需要加锁，只需要通过版本的号来决定。
不管事务执行多长时间，事务内部看到的数据是不受其它事务影响的，根据事务开始的时间不同，每个事务对同一张表，同一时刻看到的数据可能是不一样的。

有悲观并发控制和乐观并发控制两种
innoDb的MVCC采用乐观锁模式，读取数据时并不需要加锁，对于写操作，也只锁定必要的行。


悲观锁、乐观锁
悲观锁：悲观地认为每次操作数据的时候会与别人冲突，因此需要拿到锁才操作
乐观锁：乐观认为在更新数据时别人不会更新，因此不上锁，更新时判断在此期间是否有人修改了，如果修改了即操作无效，适合读多写少的场景
mvcc采用的是乐观锁模式（虽然不上锁），采用更新时版本号的变化来确认是否已被修改

行锁
MySQL的行锁是通过索引加载的，也就是说，行锁是加在索引响应的行上的，
要是对应的SQL语句没有走索引，则会全表扫描，行锁则无法实现，取而代之的是表锁，此时其它事务无法对当前表进行更新或插入操作。
*/

/*
操作系统

读取磁盘文件然后发送出去，经过几次拷贝？4次拷贝  
磁盘缓冲区到内核缓冲区，内核缓冲区到内存缓冲区，  内存缓存区到内核缓冲区，内核缓冲区到IO缓冲区

通过read从磁盘文件读取数据时：
1、磁盘控制器加载数据到磁盘内部缓冲区，之后产生中断信号，
2、cpu将磁盘缓冲区内容拷到寄存器，然后把寄存器内容拷贝到内存
write写io时
3、内存写入到cpu寄存器，cpu将寄存器内容拷贝到io缓冲区
*/

/*
网络

甲序号 2018 乙2046

若主机甲主动发起一个与主机乙的 TCP 连接，甲、乙选择的初始序列号分别为 2018 和 2046，则第三次握手 TCP 段的确认序列号是2047
对乙syn的确认


https建立链接过程
1、客户端发起https请求链接，通过dns获取到url对应的ip地址，链接ip对应的443端口，同时发送客户端支持的加密算法
2、服务端通过客户端支持的加密算法来确认发送CA整数（机构、公钥、有效期、签名算法、签名hash算法）
3、客户端验证服务端的证书
	1、证书合法性
	2、用服务端发送过来的公钥生成随机数
	3、用证书中的签名hash算法取握手信息的hash值，然后用生成的随机数对[握手信息和握手信息的hash值]进行加密，然后用公钥将随机数进行加密后，一起发送给服务端。
4、服务端收到客户端的用随机数加密的信息后
	1、先用私钥解密出随机数
	2、用随机数解密握手信息，查看是否被篡改，获取握手信息和握手信息的hash值，计算自己发送的握手信息的hash值，与客户端传回来的进行对比验证。
	3、同样使用随机字符串加密握手信息和握手信息hash值发回给到客户端
5、客户端收到服务端发送过来的握手信息后，用开始自己生成的随机数进行解密，验证被随机数加密的握手信息和握手信息hash值。


tcpip协议栈 time_wait是如何产生的
主动发起方在接收到被动方发起的fin之后进行time_wait并向被动方发送ack
*/