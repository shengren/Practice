#include <string>
#include <iostream>

using namespace std;

int d[50][50];
int n;

class CuttingBitString {
 public:
  string s;
  bool isPower5(long long x) {
    while (x % 5 == 0) x /= 5;
    return x == 1;
  }
  int check(int a, int b) {
    if (s[a] == '0') return -1;
    long long x = 0;
    for (int i = 0; b - i >= a; ++i)
      if (s[b - i] == '1') {
        x += (1LL << i);
      }
    if (isPower5(x)) return 1;
    return -1;
  }
  int getmin(string S) {
    s = S;
    n = s.size();
    for (int i = 0; i < n; ++i)
      for (int j = 0; j + i < n; ++j) {
        d[j][j + i] = check(j, j + i);
        if (d[j][j + i] == -1) {
          for (int k = 0; k < i; ++k)
            if (d[j][j + k] != -1 && d[j + k + 1][j + i] != -1) {
              int c = d[j][j + k] + d[j + k + 1][j + i];
              if ((d[j][j + i] == -1) || (d[j][j + i] > c))
                d[j][j + i] = c;
            }
        }
      }
    return d[0][n - 1];
  }
};
