class Solution {
    int extend(string s, 
               int backward_first, int backward_last, 
               int forward_first, int forward_last) {
        int length = 0;
        while (backward_last >= backward_first && 
               forward_first <= forward_last) {
            if (s[backward_last] != s[forward_first])
                break;
            ++length;
            --backward_last;
            ++forward_first;
        }
        return length;
    }
public:
    string longestPalindrome(string s) {
        if (s == "")
            return "";
        string longest_palindrome = "";
        for (int i = 0; i < s.length(); ++i) {
            int length = extend(s, 0, i, i + 1, s.length() - 1);
            if (longest_palindrome.length() < length * 2)
                longest_palindrome = s.substr(i - length + 1, length * 2);
            length = extend(s, 0, i - 1, i + 1, s.length() - 1);
            if (longest_palindrome.length() < length * 2 + 1)
                longest_palindrome = s.substr(i - length, length * 2 + 1);
        }
        return longest_palindrome;
    }
};
