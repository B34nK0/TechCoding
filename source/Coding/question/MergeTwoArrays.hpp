
/*
leetCode 88合并两个有序数组

nums1数组 长度为m + n，前半段m个数字，后半段 n个0,
nums2数组 长度为n

将num1和num2合并后以同样顺序合并到num1数组
*/

#include <vector>

using namespace std;
class MergeTwoArrays {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//采用双指针方式，指向两个数组的尾部
		int p1 = m - 1;
		int p2 = n - 1;
		int tail = m + n - 1;
		//从后判断，哪个数值大时放到数组后边
		while (p1 >= 0 || p2 >= 0) {

			int curValue = 0;
			if (p1 == -1) {
				curValue = nums2[p2];
				p2--;
			}
			else if (p2 == -1) {
				curValue = nums1[p1];
				p1--;
			}
			else if (nums1[p1] > nums2[p2]) {
				curValue = nums1[p1];
				p1--;
			}
			else {
				curValue = nums2[p2];
				p2--;
			}
			nums1[tail] = curValue;
			tail--;
		}
	}
};