
/*
leetCode 470用rand7实现rand10
即构造等概率的10个数
*/

int rand7() {
	
}

class Rand10 {
public:
	int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
            //取49个随机数里的前40个数
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
	}
};