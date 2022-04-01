/*
* leetCode 912 排序数组
* 中位数 mid = (right + left - 1) / 2
* 坐标以0开始，所以需要-1操作
快排，如果分割符不接近数组的中位数时，最差情况时n^2，所以可以采用随机数来进行优化
*/

#include <vector>
#include <time.h>
#include <algorithm>

class QuickSort {
public:
    static void SortNum(std::vector<int>& nums, int left, int right) {
        if (left < right) {
            //获取轴值的位置，且轴值左边的值均比其小
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

        //采用双指针方式
        int i = left;
        for (int j = left; j <= right - 1; ++j) {
            //当移动指针的值小于轴值时，与当前指向的i交换（因为交换的缘故，i应该是指向大于轴值的第一个值），i前进一步
            if (nums[j] <= pivot) {
                std::swap(nums[i], nums[j]);
                i = i + 1;
            }
        }
        //i即为轴值所在的下标
        std::swap(nums[i], nums[right]);
        return i;
    }

    //获取分隔符
    static int partition(std::vector<int>& nums, int left, int right) {
        //(right - left + 1) 区间个数，其在数组中的索引都是相对left的，所以需要加上left
        int index = rand() % (right - left + 1) + left ; // 随机选一个作为我们的轴值
        //将轴值放到区间最右位置
        std::swap(nums[right], nums[index]);
        //将大于轴值的值放到左边、小于的值放到右边，求出轴值所有的坐标
        return partition_swap(nums, left, right);
    }

    static void Sort(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        //随机种子
        srand((unsigned)time(NULL));
        SortNum(nums, 0, nums.size()-1);
    }
};