class TheBrickTowerEasyDivOne {
 public:
  int find(int redCount, int redHeight, int blueCount, int blueHeight) {
    if (redHeight == blueHeight) {
      if (redCount > blueCount) {
        int temp = redCount;
        redCount = blueCount;
        blueCount = temp;
      }
      if (redCount == blueCount)
        return redCount * 2;
      else
        return redCount * 2 + 1;
    }
    // different heights
    if (redCount > blueCount) {
      int temp = redCount;
      redCount = blueCount;
      blueCount = temp;
    }
    int ret = redCount;  // even
    ret += redCount; // odd, the bottom is red
    if (redCount == blueCount)  // odd, the bottom is blue
      ret += redCount;
    else
      ret += redCount + 1;
    return ret;
  }
};
