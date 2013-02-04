class Solution {
    int calculate(int n, int k) {  // Select k items from 1..n
        long long res = 1LL;
        int b = k;
        for (int a = n; a >= n - k + 1; --a) {
            res *= a;
            while (b > 1 && res % b == 0) {
                res /= b;
                b -= 1;
            }
        }
        return (int)res;
    }
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        return calculate(m + n - 2, n - 1);
    }
};
