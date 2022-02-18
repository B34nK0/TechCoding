/// <summary>
/// leetCode 69 X的平方根
/// 
/// 结果只保留 整数部分 ，小数部分将被 舍去
/// </summary>
class MySqrt {
public:
	static int sqrt(int x) {
		if (x < 2) return x;
		//平方根的范围
		int lo = 0, hi = x / 2;
		//用于存储平方根的平方值，两个int相乘需要采用64位存储
		long long tmp;
		while (lo <= hi) {
			//二分查找，在lo的基础上从偏移量进行划分
			int mid = lo + (hi - lo) / 2;
			//如果刚好为平方根值，那么返回
			tmp = (long long)mid * mid;
			if (tmp == x) return mid;
			//如果平方根的值大于x，因为舍去小数的缘故，平方根的值在mid左边
			else if (tmp > x) hi = mid - 1;
			else lo = mid + 1;
		}

		return hi;
	}
};