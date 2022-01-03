#include <queue>
#include <vector>

using namespace std;

struct Point {
	int index;
	int distance;
	Point(int index, int distance) : index(index), distance(distance) {

	}
};

class PointCompare {
public:
	static vector<vector<int>> FindKPoint(vector <vector<int>> &points, int k) {
		auto cmp = [](Point& p1, Point& p2) {
			return p1.distance < p2.distance;
		};
		priority_queue<Point, vector<Point>, decltype(cmp)> pointQueue;
		for (int i = 0; i < points.size();++i) {
			int distance = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
			if (pointQueue.size() == k) {
				Point topPoint = pointQueue.top();
				if (topPoint.distance > distance) {
					pointQueue.pop();
					pointQueue.push(Point(i, distance));
				}
			}
			else {
				pointQueue.push(Point(i, distance));
			}
		}

		vector<vector<int>> res;

		while (!pointQueue.empty()) {
			Point top = pointQueue.top();
			res.push_back(points[top.index]);
			pointQueue.pop();
		}
		return res;
	}
};