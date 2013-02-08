class Solution {
public:
    int atoi(const char *str) {
        int length = strlen(str);
        int start = 0;
        while (start < length && str[start] == ' ')  // Filter leading zeros
            ++start;
        if (start == length)  // Empty string
            return 0;
        bool is_positive = true;
        if (str[start] == '-') {  // Parse sign
            is_positive = false;
            ++start;
        } else if (str[start] == '+') {
            ++start;
        }
        if (start == length)  // No number part
            return 0;
        long long x = 0;  // For overflow cases
        for (int i = start; i < length; ++i)
            if (str[i] >= '0' && str[i] <= '9')
                x = x * 10 + (str[i] - '0');
            else  // Illegal character
                break;
        if (!is_positive)
            x = -x;
        if (x > numeric_limits<int>::max())  // Overflows
            return numeric_limits<int>::max();
        if (x < numeric_limits<int>::min())
            return numeric_limits<int>::min();
        return x;
    }
};
