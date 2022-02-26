#pragma once

/// <summary>
/// leetCode 200 在二维网格中，分别采用1、0表示陆地跟水域，求出1形成的岛屿数量
/// grid = [
//["1", "1", "1", "1", "0"],
//["1", "1", "0", "1", "0"],
//["1", "1", "0", "0", "0"],
//["0", "0", "0", "0", "0"]
//]
// 输出 1
/// </summary>

#include <vector>
using namespace std;

class NumIslands {
public :
	//深度搜索，将访问过的元素置为0
	static void dfs(vector<vector<int>>& grid, int r, int c) {
		int nr = grid.size();
		int nc = grid[0].size();

		grid[r][c] = 0;
		//上
		if (r-1 >= 0 && grid[r - 1][c] == 1) {
			dfs(grid, r - 1, c);
		}
		//下
		if (r+1 < nr && grid[r + 1][c] == 1) {
			dfs(grid, r + 1, c);
		}
		//左
		if (c-1 >= 0 &&  grid[r][c-1] == 1) {
			dfs(grid, r, c - 1);
		}
		//右
		if (c+1 < nc && grid[r][c +1] == 1) {
			dfs(grid, r, c + 1);
		}
	}

	static int GetNumsOfIslands(vector<vector<int>>& grid) {
		//如果能修改原二维数据的值，那么访问过的元素可以变更为0，不能修改的话可以采用标记数组空间
		//1、遍历二维数组
		int row = grid.size();
		int column = grid[0].size();
		int nums = 0;
		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < column; ++c) {
				//找到1的元素从其上下左右死个方向进行深度搜索、也可以采用广度搜索（使用队列替换递归）
				if (grid[r][c] == 1) {
					//岛数量+1
					nums++;
					dfs(grid, r, c);
				}
			}
		}

		return nums;
	}
};
