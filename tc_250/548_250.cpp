// Binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class KingdomAndTrees {
public:
  bool check(vector<int> h, int x) {
    vector<int> r;
    r.push_back(max(1, h[0] - x));
    for (int i = 1; i < h.size(); ++i) {
      int tar = r[i - 1] + 1;
      if (tar < h[i]) {
        r.push_back(max(tar, h[i] - x));
      } else if (tar > h[i]) {
        r.push_back(min(tar, h[i] + x));
        if (r[i] < tar)
          return false;
      } else {
        r.push_back(h[i]);
      }
    }
    return true;
  }
  int minLevel(vector<int> heights) {
    if (check(heights, 0)) return 0;
    int l = 0;
    int h = 1000000000;
    while (l + 1 < h) {
      int m = (l + h) / 2;
      bool flag = check(heights, m);
      //if (flag) cout << l << " " << h << " " << m << " " << "T" << endl;
      //else cout << l << " " << h << " " << m << " " << "F" << endl;
      if (flag) h = m;
      else l = m;
    }
    return l + 1;
  }
};
