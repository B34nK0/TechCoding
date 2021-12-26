#include <vector>
#include <utility>
#include <stack>

using namespace std;
class LargestRectangleArea {
public :
	int static GetResult(vector<int>& heights) {
		if (heights.size() <= 0) {
			return 0;
		}
		//int result = 0;

		////暴力解法：遍历每个柱子，获取柱子到左右边界的距离，算出当前柱子的面子
		//for (int index = 0; index < heights.size(); ++index) {
		//	int height = heights[index];
		//	int left = index, right = index;
		//	while (left - 1 >= 0 && heights[left-1] >= height) {
		//		--left;
		//	}

		//	while (right + 1< heights.size() && heights[right+1] >= height) {
		//		++right;
		//	}

		//	result = max(result, heights[index] * (right - left +1));
		//}


		//借用栈
		int n = heights.size();
		vector<int> left(n), right(n, n);

		stack<int> mono_stack;
		for (int i = 0; i < n; ++i) {
			while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
				right[mono_stack.top()] = i;
				mono_stack.pop();
			}
			left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
			mono_stack.push(i);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
		}
		return ans;
	}
};