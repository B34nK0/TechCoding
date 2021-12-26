#include<cstdint>

class ReverseBits {
public:
	static uint32_t Reverse(uint32_t num) {
		for (int i = 31, j = 0; i > j; --i, ++j) {
			bool iset = (num & (1 << i)) != 0;
			bool jset = (num & (1 << j)) != 0;
			if ((iset && !jset) || (jset && !iset)) {
				num = (num ^ (1 << i));
				num = (num ^ (1 << j));
			}
		}

		return num;
	}
};