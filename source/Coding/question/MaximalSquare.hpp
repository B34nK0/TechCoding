#pragma once

/*
leetCode 221 最大正方形

元素为0,1的二维数组，求出全由1组成的正方形 最大面积
*/

#include <vector>

using namespace std;

class MaximalSquare {
public:
	int GetSquare(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}

		int rows = matrix.size();
		int columns = matrix[0].size();
		int maxSide = 0;

		//记录每个元素所在边在当前位置上的值
		vector<vector<int>> eleSide(rows, vector<int>(columns, 0));
		//遍历二维数据
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				if (matrix[i][j] == 1) {
					//元素位于最左侧或者最上侧
					if (i == 0 || j == 0) {
						eleSide[i][j] = 1;
					}
					else {
						//视当前元素位置为正方形的右下角，当前元素为1时，即说明其是正方形向下扩的点
							//左方、上方、左上方元素边长延长1个位置
						eleSide[i][j] = min(eleSide[i - 1][j], min(eleSide[i][j - 1], eleSide[i - 1][j - 1])) + 1;
					}
					maxSide = max(maxSide, eleSide[i][j]);
				}
			}
		}


		return maxSide * maxSide;
	}
};