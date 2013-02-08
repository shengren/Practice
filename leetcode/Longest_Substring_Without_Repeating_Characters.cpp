class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        map<char, int> last_appear;
        int max_length = 1;
        int start = 0;
        last_appear[s[0]] = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (last_appear.find(s[i]) != last_appear.end()) {
                int prev = last_appear[s[i]];
                if (start < prev + 1)
                    start = prev + 1;
            }
            last_appear[s[i]] = i;
            if (max_length < i - start + 1)
                max_length = i - start + 1;
        }
        return max_length;
    }
};
