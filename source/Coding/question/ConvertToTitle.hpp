#include <string>

class ConvertToTitle {
public:
	static std::string Convert(int i) {
		std::string col;
		
		while (i > 26) {
			col += 'A' + (i / 26 - 1);
			i /= 26;
		}

		if (i > 0) {
			col += 'A' + i - 1;
		}

		return col;
	}
};