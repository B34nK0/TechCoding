/*
* leetCode 56 合并区间
* 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
* 
给定一组区间，合并有重叠的区间
*/

#include <vector>
#include <algorithm>

using namespace std;
class MergeIntervals {
public:
	static bool intervalCamp(const vector<int>& a, const vector<int>& b) {
		//左区间一致时比较右区间
		return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
	}

	static vector<vector<int >> Merge(vector <vector<int >> &intervals) {
		if (intervals.size() <= 1) return intervals;

		vector<vector<int>> res;

		//先进行排序 自定义比较器
		sort(intervals.begin(), intervals.end(), intervalCamp);
		/*
		java lambda表达式 比较区间的左区间大小:
		  Arrays.sort(intervals, new Comparator<int[]>() {
            public int compare(int[] interval1, int[] interval2) {
                return interval1[0] - interval2[0];
            }
        });
		*/

	
		vector<int> curr = intervals[0];
		//遍历进行合并
		for (int i = 1; i < intervals.size(); ++i) {
			//排序后，下一区间的左区间一定大于等于当前区间的左区间，那么下区间的右区间一定大于当前区间的左区间
			//如果当前区间的右区间大于等于下一区间的左区间，那么说明两者有交集
			if (curr[0] <= intervals[i][1] && intervals[i][0] <= curr[1]) {
				curr[0] = min(curr[0], intervals[i][0]);
				curr[1] = max(curr[1], intervals[i][1]);
			}
			else {
				//当前区间没有重叠
				res.emplace_back(curr);
				curr = intervals[i];
			}
		}
		res.emplace_back(curr);

		return res;
	}
};