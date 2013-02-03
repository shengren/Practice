class Solution {
public:
    int climbStairs(int n) {
        vector<int> d(n + 1, 0);
        d[0] = 1;
        for (int i = 0; i < n; ++i) {
            d[i + 1] += d[i];
            if (i <= n - 2)
                d[i + 2] += d[i];
        }
        return d[n];
    }
};
