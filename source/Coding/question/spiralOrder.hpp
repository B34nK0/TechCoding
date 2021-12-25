//顺时针输出正方形矩阵的内容

#include <vector>
using namespace std;
class spiralOrder {
public :
	static vector<int> getSpiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (0 == height) {
            return vector<int>(0);
        }

        int width = matrix[0].size();
        int left = 0, right = width - 1, top = 0, bottom = height - 1;
        vector<int> result = vector<int>();
        while (true) {
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++;
            if (top > bottom) {
                break;
            }
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;
            if (right < left) {
                break;
            }
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (bottom < top) {
                break;
            }
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