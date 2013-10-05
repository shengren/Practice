class Solution {
  public:
    int singleNumber(int A[], int n) {
      sort(A, A + n);
      for (int i = 0; i < n; ++i)
        if ((i == 0     || A[i] != A[i - 1]) &&
            (i == n - 1 || A[i] != A[i + 1]))
          return A[i];
    }
};
