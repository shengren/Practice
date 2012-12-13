#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
  return a > b;  // >= causes segment fault
}

class TomekPhone {
 public:
  int minKeystrokes(vector<int> freq, vector<int> keys) {
    vector<int> x;
    for (int i = 0; i < keys.size(); ++i)
      for (int j = 1; j <= keys[i]; ++j)
        x.push_back(j);
    if (x.size() < freq.size()) return -1;
    sort(x.begin(), x.end());
    sort(freq.begin(), freq.end(), cmp);
    int ret = 0;
    for (int i = 0; i < freq.size(); ++i)
      ret += freq[i] * x[i];
    return ret;
  }
};
