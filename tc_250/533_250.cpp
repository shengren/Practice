#include <vector>
using namespace std;

int n;
int d[50][50];

class CasketOfStar {
public:
  int maxEnergy(vector<int> weight) {
    n = weight.size();
    for (int i = 0; i < n - 1; ++i)
      d[i][i + 1] = 0;
    for (int i = 0; i < n - 2; ++i)
      d[i][i + 2] = weight[i] * weight[i + 2];
    for (int k = 3; k < n; ++k)
      for (int i = 0; i + k < n; ++i) {
        d[i][i + k] = 0;
        for (int j = i + 1; j < i + k; ++j)
          if (d[i][i + k] < d[i][j] + d[j][i + k] + weight[i] * weight[i + k])
            d[i][i + k] = d[i][j] + d[j][i + k] + weight[i] * weight[i + k];
      }
    return d[0][n - 1];
  }
};
