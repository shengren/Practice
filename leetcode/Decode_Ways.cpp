class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        // Mind empty input string
        if (len == 0)
            return 0;
        vector<int> d(len + 1, 0);
        d[0] = 1;
        for (int i = 0; i < len; ++i) {
            // Digital string can have '0' but '0' cannot be the first in a 
            // valid code
            if (s[i] != '0')
                d[i + 1] += d[i];
            if (i < len - 1) {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                    d[i + 2] += d[i];
            }
        }
        return d[len];
    }
};
