
//leetCode 54
//顺时针输出正方形矩阵的内容

#include <vector>
using namespace std;
class SpiralOrder {
public :
	static vector<int> GetSpiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (0 == height) {
            return vector<int>(0);
        }

        int width = matrix[0].size();
        //确认当前矩阵的边界，从左到右，从上到下，从右到左，从下往上，完成一层顺时针遍历
        int left = 0, right = width - 1, top = 0, bottom = height - 1;
        vector<int> result = vector<int>();
        while (true) {
            //顶部
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++;
            if (top > bottom) {
                break;
            }
            //右侧
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;
            if (right < left) {
                break;
            }
            //底部
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (bottom < top) {
                break;
            }
            //左侧
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            left++;
            if (left > right) {
                break;
            }

        }
        return result;

	}
};