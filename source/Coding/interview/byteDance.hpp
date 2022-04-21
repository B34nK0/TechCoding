/*
找到数组中两个元素相加等于指定数的所有组合
{1, 2, 5, 2, -1, 3, 1, 2}
sorted : {-1, 1, 1, 2, 2, 2, 3, 5}

[1,3] [2,2] [2, 2] [5, -1], [2,2] [3, 1] 
*/
#include <vector>
#include <algorithm>

class FindMatchVector {
public:
	static std::vector<std::vector<int>> GetVec(std::vector<int>& nums, int target) {
		std::vector<std::vector<int>> ans;
		int first = 0, second = nums.size()-1;

		sort(nums.begin(), nums.end());
		while (first < second) {
			std::vector<int> matchNum;
			
			int firstNum = nums[first];
			int secondNum = nums[second];
			if (firstNum + secondNum == target) {
				matchNum.emplace_back(firstNum);
				matchNum.emplace_back(secondNum);
				ans.emplace_back(matchNum);
			}

			if (nums[first + 1] != firstNum && nums[second - 1] != secondNum) {
				first++;
				second--;
			}
			else if (nums[first + 1] == firstNum) {
				first++;
			}
			else if (nums[second - 1] == secondNum) {
				second--;
			}

		}

		if (first == second) {
			if (nums[first] + nums[second] == target) {
				vector<int> matchNum = { nums[first], nums[second] };
				ans.emplace_back(matchNum);
			}
		}

		return ans;
	}
};