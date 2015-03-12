class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    for (int k = 0; k < 16; ++k) {
      if (((n & 1 << k) == 0) != ((n & 1 << 31 - k) == 0)) {
        n ^= 1 << k;
        n ^= 1 << 31 - k;
      }
    }
    return n;
  }
};
