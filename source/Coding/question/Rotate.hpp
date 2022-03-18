#include <vector>
/*
leetCode 48 旋转图像
给出n*n的矩阵，顺时针旋转90度 输出旋转后的矩阵
*/
using namespace std;
class Rotate {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    //旋转的规律，matrix[col][n-row-1] = matrxi[row][col]
    //行的数据会旋转到对应列跟行位置
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //旋转的层次
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1)/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};