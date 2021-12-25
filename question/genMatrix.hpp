// 顺时针返回矩阵内容

#pragma once
#include <vector>

using namespace std;
class genMatrix {
public:
	static vector<vector<int>> genMatrixByN(int n) {
		vector<vector<int>> matrix(n, vector<int>(n));

		int left = 0, right = n - 1, top = 0, bottom = n - 1;
		int num = 1, side = n*n;
		while (num <= side) {
			for (int i = left; i <= right; ++i) {
				matrix[top][i] = num++;
			}
			top++;
			for (int i = top; i <= bottom; ++i) {
				matrix[i][right] = num++;
			}
			right--;
			for (int i = right; i >= left; i--) {
				matrix[bottom][i] = num++;
			}
			bottom--;
			for (int i = bottom; i >= top; i--) {
				matrix[i][left] = num++;
			}
			left++;
		}

		return matrix;
	}
};