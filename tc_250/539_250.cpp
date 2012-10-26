#include <vector>
#include <algorithm>
using namespace std;

struct Range {
  int a, b;
  Range(int _a, int _b) {
    a = _a;
    b = _b;
  }
  bool operator<(const Range &rhs) const {
    if (a == rhs.a)
      return b < rhs.b;
    return a < rhs.a;
  }
};
int n;
vector<Range> res;

void choose(int k, const vector<int> &lb, const vector<int> &ub, Range cr) {
  if (k == n) {
    res.push_back(cr);
    return;
  }
  choose(k + 1, lb, ub, cr);
  choose(k + 1, lb, ub, Range(cr.a + lb[k], cr.b + ub[k]));
}

class Over9000Rocks {
public:
  int countPossibilities(vector<int> lowerBound, vector<int> upperBound) {
    n = lowerBound.size();
    res.clear();
    choose(0, lowerBound, upperBound, Range(0, 0));
    sort(res.begin(), res.end());
    int ret = 0;
    Range r(9000, 9000);
    for (int i = 0; i < res.size(); ++i) {
      if (r.b < res[i].a) {
        r.a = res[i].a;
        r.b = res[i].b;
        ret += r.b - r.a + 1;
      } else if (r.b < res[i].b) {
        r.a = r.b + 1;
        r.b = res[i].b;
        ret += r.b - r.a + 1;
      }
    }
    return ret;
  }
};
