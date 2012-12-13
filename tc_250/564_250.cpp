class KnightCircuit2 {
 public:
  int maxSize(int w, int h) {
    if (w > h) {int t = w; w = h; h = t;}
    if (w == 1) return 1;
    if (w == 3 && h == 3) return 8;  // missed this case
    if (w > 2) return w * h;
    // w == 2
    return 1 + (h - 1) / 2;
  }
};
