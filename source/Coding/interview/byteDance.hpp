/*
�ҵ�����������Ԫ����ӵ���ָ�������������
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

Java ��
 
A�û�ͬʱ������������

���������벻��������������

һ���߳̽������ݹ���ã��׳��쳣���������������ʲôӰ�죿

threadlocal�ڴ�й©���⣿һ�����ڴ�й©��

�������ж϶���ɴ

�����ĸ�root�ж϶��󲻿ɴ

���߳���ڴ��û���Ϣ��ͻȻ���˸�GC�������ñ����գ�

*/

/*
kafka��rabbitmq

Ϊʲô��rabbitmq
rabbitmq֧�ֶ�������

rabbitmq�߿���

*/

/*
redis ���Ӹ���

���Ӹ���ʵ�ֵ�Ŀ�ģ�
1���������࣬ʵ���������ݵ��ȱ���
2�����ؾ��⣬�����Ӹ��ƵĻ����ϣ���϶�д���룬��д����ʱ���ӵ����ڵ㣬������ʱ���ӵ��ӽڵ㣬�ڶ���д�ٵĳ����£����Խ����ַ�������ӽڵ����ṩ��������
3�����ϻָ��������ڵ����ʱ�����������ӽڵ㣬���ٻָ�����
4���߿��ã����ڱ��ͼ�Ⱥʵ�ֵĻ���

ʵ�ֵ�ԭ��
1���������ӽ׶Σ��ӽڵ㱣�����ڵ��ip��port���ӽڵ�ÿһ����ø������ӳ��������ڵ㽨�����ӣ�
	������ӳɹ����ӽڵ��Ϊ����һ��ר�Ŵ����ƹ������ļ��¼�����������������ĸ��ƹ����������RDB�ļ��������������
	���ڵ���յ��ӽڵ�socket��accept����Ϊ��Ϊ�ͻ��˲�ά����socket״̬
	�ӽڵ㷢��pingȷ��socket�Ƿ���ã���ʱ�Ͽ����ԣ����õ��ر���ʾ���ڵ㵱ǰ�޷�����ʱ���Ͽ����ԡ�

	�����ڵ���������ʱ��Ҫ���������֤

	�ӽڵ�������ڵ㷢�ͽڵ���Ϣ�����ڱ��������ڵ㣬�����ն�

2������ͬ���׶�
	�ӽڵ㷢��psync��ͬ���׶η�Ϊȫ�����ƺͲ��ָ���

3��������׶�
	���ڵ㽫�Լ�ִ�е�д����͸��ӽڵ㣬�ӽڵ�������ִ�У��Ӷ���֤���ӽڵ����ݵ�һ���ԡ�
	��������첽�Ĺ��̣������ȴ��ӽڵ��ȷ�ϣ��������֮���������һ��������

	���ݲ�һ�µĳ̶ȣ������ӽڵ�֮�������״�������ڵ�д�����ִ��Ƶ�ʡ��Լ����ڵ��е�repl-disable-tcp-nodelay���õ��йء�

	repl-disable-tcp-nodelay���������Ƿ����ӳٷ��ͣ�Ϊtrueʱ��tcp����һ���������ٷ��ͣ�������Ӿ��ӳ٣�Ϊnoʱ����TCP���������ڵ�����ݷ��͸��ӽڵ㣬�������ӵ��ӳٱ�С

ȫ������
1�����ڵ���յ���������ʱ������ǲ��֣������ж��޷�����ʱ������ִ��bgsave���forkһ���ӽ��̽���RDB�־û���ͬʱʹ��һ������ȥ�����ƻ�����������¼�˿̿�ʼ�Ĳ�������
2�����ڵ�bgsaveִ����֮�󣬽�RDB�ļ����͸��ӽڵ㣬�ӽڵ�������Լ��ľ����ݺ����RDB
3�����ڵ㽫���ƻ�������д����͸��ӣ��ӻ�ͬ��������ͬ����״̬
4������ӽڵ㿪����AOF����ᴥ��bgrewriteaof��ִ�У��Ӷ���֤AOF�ļ����������ڵ������״̬


���ָ���
1������ƫ����
2�����ƻ�ѹ������
3������������ID(runid)
*/

/*
tcp 

Ϊʲô����time_wait״̬
�������ȴ��������յ���ack

ΪʲôҪ�ȴ�2��MSL
msl�����������ʱ��
*/