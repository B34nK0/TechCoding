// 经典快排

#include <vector>

class quickSort {
public:
    static void sortNum(std::vector<int> nums, int l, int r) {
        int index = (r - l) / 2; 
    }

    static std::vector<int> sort(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums;
        }

        sortNum(nums, 0, nums.size());
    }
}