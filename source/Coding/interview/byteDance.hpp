/*
找到数组中两个元素相加等于指定数的所有组合
{1, 2, 5, 2, -1, 3, 1, 2}
sorted : {-1, 1, 1, 2, 2, 2, 3, 5}

[1,3] [2,2] [2, 2] [5, -1], [2,2] [3, 1] 
*/
#include <vector>
#include <algorithm>

class FindMatchVector {
public:
	static std::vector<std::vector<int>> GetVec(std::vector<int>& nums, int target) {
		std::vector<std::vector<int>> ans;
		int first = 0, second = nums.size()-1;

		sort(nums.begin(), nums.end());
		while (first < second) {
			std::vector<int> matchNum;
			
			int firstNum = nums[first];
			int secondNum = nums[second];
			if (firstNum + secondNum == target) {
				matchNum.emplace_back(firstNum);
				matchNum.emplace_back(secondNum);
				ans.emplace_back(matchNum);
			}

			if (nums[first + 1] != firstNum && nums[second - 1] != secondNum) {
				first++;
				second--;
			}
			else if (nums[first + 1] == firstNum) {
				first++;
			}
			else if (nums[second - 1] == secondNum) {
				second--;
			}

		}

		if (first == second) {
			if (nums[first] + nums[second] == target) {
				vector<int> matchNum = { nums[first], nums[second] };
				ans.emplace_back(matchNum);
			}
		}

		return ans;
	}
};

/*

Java 锁
 
A用户同时发了两条请求，

可重入锁与不可重入锁的区别？

一个线程进来，递归调用，抛出异常，可重入锁会产生什么影响？

threadlocal内存泄漏问题？一定会内存泄漏吗？

从哪里判断对象可达？

根据哪个root判断对象不可达？

在线程入口存用户信息，突然来了个GC，弱引用被回收？

*/

/*
kafka、rabbitmq

为什么用rabbitmq


rabbitmq高可用

*/

/*
redis 主从复制

主从复制实现的目的：
1、数据冗余，实现来了数据的热备份
2、负载均衡，在主从复制的基础上，配合读写分离，当写数据时链接到主节点，读数据时链接到从节点，在读多写少的场景下，可以将读分发到多个从节点来提供并发能力
3、故障恢复，当主节点故障时，可以升级从节点，快速恢复故障
4、高可用，是哨兵和集群实现的基础

实现的原理：
1、建立链接阶段：从节点保存主节点的ip和port，从节点每一秒调用复制链接尝试与主节点建立链接，
	如果链接成功，从节点会为建立一个专门处理复制工作的文件事件处理器，负责后续的复制工作，如接收RDB文件、接收命令传播等
	主节点接收到从节点socket的accept后，认为其为客户端并维护其socket状态
	从节点发送ping确认socket是否可用，超时断开重试，可用但回报表示主节点当前无法处理时，断开重试。

	若主节点设置密码时需要进行身份验证

	从节点会向主节点发送节点信息，用于保存在主节点，互成终端

2、数据同步阶段
	从节点发送psync，同步阶段分为全量复制和部分复制

3、命令传播阶段
	主节点将自己执行的写命令发送给从节点，从节点接收命令并执行，从而保证主从节点数据的一致性。
	命令传播是异步的过程，并不等待从节点的确认，因此主从之间存在数据一致性问题

	数据不一致的程度，与主从节点之间的网络状况、主节点写命令的执行频率、以及主节点中的repl-disable-tcp-nodelay配置等有关。

	repl-disable-tcp-nodelay用于配置是否开启延迟发送，为true时，tcp会攒一定的数据再发送，这样会加剧延迟，为no时，即TCP会立马将主节点的数据发送给从节点，带宽增加但延迟变小

全量复制
1、主节点接收到复制请求时（如果是部分，但主判断无法部分时），主执行bgsave命令，fork一个子进程进行RDB持久化，同时使用一个缓存去（复制缓冲区）来记录此刻开始的操作命令
2、主节点bgsave执行完之后，将RDB文件发送给从节点，从节点先清除自己的旧数据后加载RDB
3、主节点将复制缓冲区的写命令发送给从，从会同步到与主同样的状态
4、如果从节点开启了AOF，则会触发bgrewriteaof的执行，从而保证AOF文件更新至主节点的最新状态


部分复制

*/

/*
tcp 

为什么存在time_wait状态

为什么要等待2个MSL

*/