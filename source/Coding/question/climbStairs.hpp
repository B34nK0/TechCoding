/*
爬楼梯，每次有1格或2格的爬法
求解n层楼梯可以有多种方式爬到楼顶
*/
class ClimbStairs {
public:
	static int CalStep(int n) {
		if (n == 1) return 1;
		if (n == 2) return 2;

		int prev2 = 1, prev1 = 2;
		int count = 0;
		while (n - 2 != 0) {
			count = prev1 + prev2;
			prev2 = prev1;
			prev1 = count;
			n--;
		}

		return count;
	}
};