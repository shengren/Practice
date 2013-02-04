class Solution {
    string generatePermutation(int n, int p, int k, 
                               vector<int> &num, vector<bool> &has) {
        if (p > n)
            return "";
        int x = 0;
        while (k > num[n - p] * (x + 1))
            ++x;
        k -= num[n - p] * x;
        for (int i = 1; i <= n; ++i)
            if (has[i]) {
                if (x == 0) {
                    has[i] = false;
                    return char('0' + i) + 
                           generatePermutation(n, p + 1, k, num, has);
                } else {
                    --x;
                }
            }
    }
public:
    string getPermutation(int n, int k) {
        vector<int> num(9);
        num[0] = 1;
        for (int i = 1; i <= 8; ++i)
            num[i] = num[i - 1] * i;

        vector<bool> has(10, true);

        return generatePermutation(n, 1, k, num, has);
    }
};
