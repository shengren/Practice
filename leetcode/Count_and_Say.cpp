class Solution {
    string convert(int n) {
        ostringstream oss;
        oss << n;
        return oss.str();
    }
    string increment(string s) {
        string next_s = "";
        for (int i = 0; i < s.size(); ++i) {
            char digit = s[i];
            int count = 1;
            while (i + 1 < s.size() && s[i + 1] == digit) {
                ++i;
                ++count;
            }
            next_s += convert(count) + digit;
        }
        return next_s;
    }
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
        string s = "1";
        while (--n)
            s = increment(s);
        return s;
    }
};
