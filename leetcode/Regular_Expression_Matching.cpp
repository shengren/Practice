class Solution {
    string a;
    string b;
    unordered_map<long long, bool> cache;
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
        if (b[y] == '.') {
            if (y + 1 < b.length() && b[y + 1] == '*') {
                bool is_match = false;
                for (int i = 0; x + i <= a.length(); ++i)
                    if (isMatch(x + i, y + 2)) {
                        is_match = true;
                        break;
                    }
                cache[key] = is_match;
                return is_match;
            } else {
                if (x == a.length()) {
                    cache[key] = false;
                    return false;
                }
                bool is_match = isMatch(x + 1, y + 1);
                cache[key] = is_match;
                return is_match;
            }
        }
        if (y + 1 < b.length() && b[y + 1] == '*') {
            if (x == a.length()) {
                bool is_match = isMatch(x, y + 2);
                cache[key] = is_match;
                return is_match;
            }
            bool is_match = isMatch(x, y + 2);
            if (!is_match) {
                for (int i = 1;
                     x + i <= a.length() && a[x + i - 1] == b[y];
                     ++i) {
                    if (isMatch(x + i, y + 2)) {
                        is_match = true;
                        break;
                    }
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
        b = string(p);
        cache.clear();
        return isMatch(0, 0);
    }
};
