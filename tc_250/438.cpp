#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Interval {
  int b, e, cur;
  double val;
  Interval(int __b, int __e) {
    b = __b;
    e = __e;
    cur = 0;
    val = e - b;
  }
};

bool comp(const Interval &x, const Interval &y) {
    if (x.val == y.val) {
      return x.b < y.b;
    }
    return x.val < y.val;
}

class UnluckyIntervals {
  public:
    vector<int> getLuckiest(vector<int> luckySet, int n) {
      sort(luckySet.begin(), luckySet.end());
      vector<int> ret;
      bool done = false;
      vector<Interval> ivs;

      for (int i = 0; i < luckySet.size(); ++i) {
        if ((i == 0 && luckySet[i] == 2) ||
            (i > 0 && luckySet[i] - luckySet[i - 1] == 2)) {
          ret.push_back(luckySet[i] - 1);
          if (ret.size() == n) {
            done = true;
            break;
          }
        } else {
          if (i == 0 && luckySet[i] > 2) {
            Interval iv(1, luckySet[i] - 1);
            ivs.push_back(iv);
          }
          if (i > 0 && luckySet[i] - luckySet[i - 1] > 2) {
            Interval iv(luckySet[i - 1] + 1, luckySet[i] - 1);
            ivs.push_back(iv);
          }
        }
        ret.push_back(luckySet[i]);
        if (ret.size() == n) {
          done = true;
          break;
        }
      }
      if (done)
        return ret;
      
      while (!ivs.empty()) {
        sort(ivs.begin(), ivs.end(), comp);
        
        for (int i = 0; i < ivs.size(); ++i) printf("(%d, %d, %d) ", ivs[i].b, ivs[i].e, ivs[i].cur);
        printf("\n");

        int i = 0;

        ret.push_back(ivs[i].b + ivs[i].cur);
        if (ret.size() == n) {
          done = true;
          break;
        }
        if (ivs[i].e - ivs[i].cur != ivs[i].b + ivs[i].cur) {
          ret.push_back(ivs[i].e - ivs[i].cur);
          if (ret.size() == n) {
            done = true;
            break;
          }
        }

        ++ivs[i].cur;
        ivs[i].val = (double)(ivs[i].e - ivs[i].b) + (double)ivs[i].cur * (double)(ivs[i].e - ivs[i].b - ivs[i].cur);
        if (ivs[i].cur > (ivs[i].e - ivs[i].b) / 2) {
          ivs.erase(ivs.begin());
        }
      }
      if (done)
        return ret;

      int last = luckySet[luckySet.size() - 1] + 1;
      while (ret.size() < n) {
        ret.push_back(last);
        last++;
      }
      return ret;
    }
};