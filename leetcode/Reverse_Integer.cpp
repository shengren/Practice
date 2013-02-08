class Solution {
public:
    int reverse(int x) {
        bool is_negative = false;
        if (x < 0) {
            is_negative = true;
            x = -x;
        }
        int rx = 0;
        while (x > 0) {
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        return is_negative ? -rx : rx;
    }
};
