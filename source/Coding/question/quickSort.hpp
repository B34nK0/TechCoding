/*
快排，如果分割符不接近数组的中位数时，最差情况时n^2，所以可以采用随机数来进行优化
*/

#include <vector>
#include <time.h>
#include <algorithm>

class QuickSort {
public:
    static void SortNum(std::vector<int>& nums, int l, int r) {
        if (l < r) {
            int index = partition(nums, l, r);
            SortNum(nums, l, index - 1);
            SortNum(nums, index + 1, r);
        }
    }

    static int partition_swap(std::vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    //获取分隔符
    static int partition(std::vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1)+1; // 随机选一个作为我们的主元
        std::swap(nums[r], nums[i]);
        return partition_swap(nums, l, r);
    }

    static void Sort(std::vector<int>& nums) {
        srand((unsigned)time(NULL));
        SortNum(nums, 0, nums.size()-1);
    }
};