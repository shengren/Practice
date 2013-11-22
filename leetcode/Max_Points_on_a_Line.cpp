/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
  public:
    int maxPoints(vector<Point> &points) {
      const int n = points.size();
      if (n <= 1)
        return n;

      int max_num = 0;

      for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
          int num = 0;
          if (points[i].x == points[j].x) {
            for (int k = 0; k < n; ++k)
              if (points[k].x == points[i].x)
                ++num;
          } else {
            for (int k = 0; k < n; ++k)
              if ((points[i].y - points[j].y) * (points[k].x - points[i].x) ==
                  (points[i].x - points[j].x) * (points[k].y - points[i].y))
                ++num;
          }
          if (max_num < num)
            max_num = num;
        }

      return max_num;
    }
};
