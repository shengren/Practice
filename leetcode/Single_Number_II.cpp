class Solution {
  public:
    int singleNumber(int A[], int n) {
      if (n == 1)
        return A[0];
      sort(A, A + n);
      int current = A[0];
      int counter = 1;
      for (int i = 1; i < n; ++i)
        if (A[i] != current) {
          if (counter != 3)
            return current;
          current = A[i];
          counter = 1;
        } else {
          counter++;
        }
      return current;  // the largest number is singular
    }
};
