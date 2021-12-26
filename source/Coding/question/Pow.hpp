class Pow {
public:
	static double CalculatePow(double x, int n) {
		long long pow = n;
		bool isNeg = n < 0;
		pow = isNeg ? -pow : pow;
		double res = 1.0;
		double xpow = x;
		while (pow != 0) {
			if (pow & 1) {
				res *= xpow;
			}
			xpow *= xpow;
			pow >>= 1;
		}

		return isNeg ? 1.0 / res : res;
	}
};