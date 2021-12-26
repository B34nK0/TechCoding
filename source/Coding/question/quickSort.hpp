// 经典快排

#include <vector>

class QuickSort {
public:
    static void SortNum(std::vector<int> nums, int l, int r) {
        int index = (r - l) / 2;
    }

    static std::vector<int> Sort(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums;
        }

        SortNum(nums, 0, nums.size());
    }
};