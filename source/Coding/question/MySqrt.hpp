class MySqrt {
public:
	static int sqrt(int x) {
		if (x < 2) return x;
		int lo = 0, hi = x / 2;
		//用于存储平方根的平方值，两个int相乘需要采用64位存储
		long long tmp;
		while (lo <= hi) {
			//二分查找
			int mid = lo + (hi - lo) / 2;
			tmp = (long long)mid * mid;
			if (tmp == x) return mid;
			else if (tmp > x) hi = mid - 1;
			else lo = mid + 1;
		}

		return hi;
	}
};