#include <iostream>
#include <vector>
using namespace std;

class MergersDivOne {
public:
  double findMaximum(vector<int> revenues) {
    sort(revenues.begin(), revenues.end());
    double ret = (revenues[0] + revenues[1]) * 0.5;
    for (int i = 2; i < revenues.size(); ++i)
      ret = (ret + revenues[i]) * 0.5;
    return ret;
  }
};
