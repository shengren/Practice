#include <string>
#include <vector>
#include <iostream>
using namespace std;

class ImportantSequence {
public:
  int getCount(vector<int> B, string operators) {
    long long lb = 0;
    const long long MAX_INT = 50000000001LL;
    long long ub = MAX_INT;
    bool x_positive = true;
    long long num = 0;
    for (int i = 0; i < operators.size(); ++i) {
      if (operators[i] == '+') {
        x_positive = !x_positive;
        num = B[i] - num;
      } else {
        num -= B[i];
      }
      if (x_positive) {
        lb = max(lb, -num);
      } else {
        ub = min(ub, num);
      }
    }
    if (lb >= ub) return 0;
    else if (ub == MAX_INT) return -1;
    return ub - lb - 1;
  }
};
