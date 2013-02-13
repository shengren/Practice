class Solution {
    string a;
    string b;
    unordered_map<long long, bool> cache;
    vector<int> num_not_star;    
    string shrink(string s) {
        string t = "";
        for (int i = 0; i < s.length(); ++i)
            if (i > 0 && s[i] == '*' && s[i - 1] == '*')
                continue;
            else
                t += s[i];
        return t;
    }
    bool isMatch(int x, int y) {
        long long key = (long long)x * (b.length() + 1) + y;
        if (cache.find(key) != cache.end())
            return cache[key];
        if (x == a.length() && y == b.length()) {
            cache[key] = true;
            return true;
        }
        if (y == b.length()) {
            cache[key] = false;
            return false;
        }
        if (b == "*") {
            cache[key] = true;
            return true;
        }
        if (b[y] == '?') {
            if (x == a.length()) {
                cache[key] = false;
                return false;
            }
            bool is_match = isMatch(x + 1, y + 1);
            cache[key] = is_match;
            return is_match;
        }
        if (b[y] == '*') {
            if (x == a.length()) {
                bool is_match = isMatch(x, y + 1);
                cache[key] = is_match;
                return is_match;
            }
            bool is_match = false;
            for (int i = 0; x + i + num_not_star[y] <= a.length(); ++i) {
                if (isMatch(x + i, y + 1)) {
                    is_match = true;
                    break;
                }
            }
            cache[key] = is_match;
            return is_match;
        }
        if (x == a.length()) {
            cache[key] = false;
            return false;
        }
        if (a[x] != b[y]) {
            cache[key] = false;
            return false;
        }
        bool is_match = isMatch(x + 1, y + 1);
        cache[key] = is_match;
        return is_match;
    }
public:
    bool isMatch(const char *s, const char *p) {
        a = string(s);
        b = shrink(string(p));
        cache.clear();
        num_not_star.resize(b.length());
        if (b.length() > 0)
            num_not_star[b.length() - 1] = (b[b.length() - 1] == '*') ? 0 : 1;
        for (int i = b.length() - 2; i >= 0; --i) {
            num_not_star[i] = num_not_star[i + 1];
            if (b[i] != '*')
                num_not_star[i]++;
        }
        return isMatch(0, 0);
    }
};
