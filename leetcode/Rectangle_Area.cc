class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int ret = (C - A) * (D - B);
    ret += (G - E) * (H - F);
    ret -= GetOverlap(A, C, E, G) * GetOverlap(B, D, F, H);
    return ret;
  }

 private:
  int GetOverlap(int a, int b, int c, int d) {
    if (c <= a) {
      if (d <= a) {
        return 0;
      } else if (d < b) {
        return d - a;
      } else {  // d >= b
        return b - a;
      }
    } else if (c < b) {
      if (d < b) {
        return d - c;
      } else {  // d >= b
        return b - c;
      }
    } else {  // c >= b
      return 0;
    }
  }
};
