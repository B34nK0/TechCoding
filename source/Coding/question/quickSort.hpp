/*
快排，如果分割符不接近数组的中位数时，最差情况时n^2，所以可以采用随机数来进行优化
*/

#include <vector>
#include <time.h>
#include <algorithm>

class QuickSort {
public:
    static void SortNum(std::vector<int>& nums, int left, int right) {
        if (left < right) {
            //获取轴值的位置，且轴值左边的值均比起小
            //右边的值均比其大
            int index = partition(nums, left, right);
            //排序左边的值
            SortNum(nums, left, index - 1);
            //排序右边的值
            SortNum(nums, index + 1, right);
        }
    }

    static int partition_swap(std::vector<int>& nums, int left, int right) {
        //当前轴值
        int pivot = nums[right];

        int i = left - 1;
        for (int j = left; j <= right - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums[right]);
        return i + 1;
    }

    //获取分隔符
    static int partition(std::vector<int>& nums, int left, int right) {
        //(right - left + 1) 区间个数，其在数组中的索引都是相对left的，所以需要加上left
        int index = rand() % (right - left + 1)+ left ; // 随机选一个作为我们的轴值
        //将轴值放到区间最右位置
        std::swap(nums[right], nums[index]);
        //将大于轴值的值放到左边、小于的值放到右边
        return partition_swap(nums, left, right);
    }

    static void Sort(std::vector<int>& nums) {
        //随机种子
        srand((unsigned)time(NULL));
        SortNum(nums, 0, nums.size()-1);
    }
};