#include <cmath>
#include <vector>
#include <string>
using namespace std;

class EvenRoute {
public:
  string isItPossible(vector<int> x, vector<int> y, int wantedParity) {
    bool oo = false;
    bool oe = false;
    bool po = false;
    bool pe = false;
    for (int i = 0; i < x.size(); ++i) {
      int d = abs(x[i]) + abs(y[i]);
      if (d % 2 == 1) oo = true;
      if (d % 2 == 0) oe = true;
    }
    for (int i = 0; i < x.size(); ++i)
      for (int j = i + 1; j < x.size(); ++j) {
        int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        if (d % 2 == 1) po = true;
        if (d % 2 == 0) pe = true;
      }
    if (wantedParity == 0) {
      if (!oe && !po) return “CANNOT”;
      return “CAN”;
    } else {
      if (!oo && !po) return “CANNOT”;
      return “CAN”;
    }
  }
};
