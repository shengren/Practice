class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<bool> is_valid(n, false);
        stack<int> left_parentheses;
        for (int i = 0; i < n; ++i)
            if (s[i] == '(') {
                left_parentheses.push(i);
            } else {
                if (!left_parentheses.empty()) {  // Forgot this check at first
                    int matched_pos = left_parentheses.top();
                    left_parentheses.pop();
                    is_valid[matched_pos] = is_valid[i] = true;
                }
            }
        int longest_length = 0;
        bool is_counting = false;
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (is_valid[i]) {
                if (!is_counting) {
                    is_counting = true;
                    count = 1;
                } else {
                    ++count;
                }
            } else {
                is_counting = false;
                if (longest_length < count)
                    longest_length = count;
                count = 0;
            }
        // Forgot this update at first
        if (is_counting && longest_length < count)
            longest_length = count;
        return longest_length;
    }
};
