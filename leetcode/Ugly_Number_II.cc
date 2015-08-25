class Solution {
 public:
  int nthUglyNumber(int n) {
    while (n > un.size()) {
      if (un[p2] * 2 <= un[p3] * 3) {
        if (un[p2] * 2 <= un[p5] * 5) {
          un.push_back(un[p2] * 2);
        } else {
          un.push_back(un[p5] * 5);
        }
      } else {
        if (un[p3] * 3 <= un[p5] * 5) {
          un.push_back(un[p3] * 3);
        } else {
          un.push_back(un[p5] * 5);
        }
      }
      
      while (un[p2] * 2 <= un.back()) ++p2;
      while (un[p3] * 3 <= un.back()) ++p3;
      while (un[p5] * 5 <= un.back()) ++p5;
    }

    return un[n - 1];
  }

  Solution() : p2(0), p3(0), p5(0) {
    un.push_back(1);
  }

 private:
  int p2;
  int p3;
  int p5;
  vector<int> un;
};
