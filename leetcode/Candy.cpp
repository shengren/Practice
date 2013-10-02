class Solution {
  public:
    int candy(vector<int> &ratings) {
      const int N = ratings.size();

      if (N == 0)
        return 0;

      vector<int> l(N, 0);  // # of consecutive smaller elements on the left
      vector<int> r(N, 0);  // # of consecutive smaller elements on the right
      for (int i = 1; i < N; ++i)
        if (ratings[i] > ratings[i - 1])
          l[i] = l[i - 1] + 1;
      for (int i = N - 2; i >= 0; --i)
        if (ratings[i] > ratings[i + 1])
          r[i] = r[i + 1] + 1;

      int total_candies = 0;
      for (int i = 0; i < N; ++i)
        if (l[i] == 0 && r[i] == 0)
          total_candies++;
        else
          total_candies += max(l[i], r[i]) + 1;
      return total_candies;
    }
};
