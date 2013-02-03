class Solution {
    string s1;
    string s2;
    bool isMatching(int first_s1, int last_s1,
                    int first_s2, int last_s2) {
        vector<int> char_count(26, 0);
        for (int i = 0; i <= last_s1 - first_s1; ++i) {
            ++char_count[s1[first_s1 + i] - 'a'];
            --char_count[s2[first_s2 + i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
            if (char_count[i] != 0)
                return false;
        return true;
    }
    bool check(int first_s1, int last_s1,
               int first_s2, int last_s2) {  // [first, last]
        if (first_s1 > last_s1)  // Empty string
            return true;
        if (first_s1 == last_s1)  // Single character string
            return s1[first_s1] == s2[first_s2];
        for (int i = first_s2; i < last_s2; ++i) {
            // [first_s2, i] [i + 1, last_s2]
            // No swapping
            if (isMatching(first_s1, first_s1 + (i - first_s2),
                           first_s2, i) &&
                isMatching(last_s1 - (last_s2 - i - 1), last_s1,
                           i + 1,                       last_s2)) {
                if (check(first_s1, first_s1 + (i - first_s2),
                          first_s2, i) && 
                    check(last_s1 - (last_s2 - i - 1), last_s1,
                          i + 1,                       last_s2))
                    return true;
            }
            // Swapping
            if (isMatching(first_s1, first_s1 + (last_s2 - i - 1),
                           i + 1,    last_s2) &&
                isMatching(last_s1 - (i - first_s2), last_s1,
                           first_s2,                 i)) {
                if (check(first_s1, first_s1 + (last_s2 - i - 1),
                          i + 1,    last_s2) &&
                    check(last_s1 - (i - first_s2), last_s1,
                          first_s2,                 i))
                    return true;
            }
        }
        return false;
    }
public:
    bool isScramble(string _s1, string _s2) {
        s1 = _s1;
        s2 = _s2;
        return check(0, s1.length() - 1,
                     0, s2.length() - 1);
    }
};

