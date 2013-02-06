class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_negative = (dividend >= 0) ^ (divisor >= 0);
        long long abs_dividend = dividend;
        if (abs_dividend < 0)
            abs_dividend = -abs_dividend;
        long long abs_divisor = divisor;
        if (abs_divisor < 0)
            abs_divisor = -abs_divisor;
        vector<long long> multiple(10, 0);
        vector<int> count(10, 0);
        multiple[1] = abs_divisor;
        count[1] = 1;
        for (int i = 2; i < 10; ++i)
            for (int j = 0; j < 10; ++j) {
                multiple[i] += multiple[i - 1];
                count[i] += count[i - 1];
            }
        int quotient = 0;
        for (int i = 9; i >= 1; --i) {
            if (multiple[i] <= 0)
                continue;
            while (abs_dividend >= multiple[i]) {
                abs_dividend -= multiple[i];
                quotient += count[i];
            }
        }
        if (is_negative)
            return -quotient;
        return quotient;
    }
};
