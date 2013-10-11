class Solution {
  public:
    int singleNumber(int A[], int n) {
      class Solution {
        public:
          int singleNumber(int A[], int n) {
            int singular = 0;
            for (int i = 0; i < n; ++i)
              singular ^= A[i];
            return singular;
          }
      };
    }
};
