class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (x == 0)
            return 0;
        bool positive_power = true;
        if (n < 0) {
            positive_power = false;
            n = -n;
        }
        double b[11];
        b[0] = x;  // 10^0
        for (int i = 1; i < 11; ++i) {
            b[i] = 1.0f;
            for (int j = 0; j < 10; ++j)
                b[i] *= b[i - 1];
        }
        double res = 1.0;
        int k = 0;
        while (n > 0) {
            for (int i = 1; i <= n % 10; ++i)
                res *= b[k];
            ++k;
            n /= 10;
        }
        if (!positive_power)
            res = 1.0 / res;
        return res;
    }
};
