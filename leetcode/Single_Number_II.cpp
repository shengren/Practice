class Solution {
  public:
    int singleNumber(int A[], int n) {
      vector<int> bit(32, 0);
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < 32; ++j)
          if (A[i] & (1 << j))
            bit[j]++;
      int singular = 0;
      for (int j = 0; j < 32; ++j)
        if (bit[j] % 3 != 0)
          singular |= (1 << j);
      return singular;
    }
};
