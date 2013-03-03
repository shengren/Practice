class Solution {
    int n;
    vector<int> shift_left;  // Longest shifts can accelerate isPalindrome().
    vector<int> shift_right;
    vector<int> num_cuts;
    bool isPalindrome(const string &s, int a, int b) {
        while (a < b) {
            if (s[a] != s[b])
                return false;
            if (a + shift_right[a] <= b - shift_left[b] &&
                shift_right[a] != shift_left[b])
                return false;  // Missed this check at first
            a += shift_right[a];
            b -= shift_left[b];
        }
        return true;
    }
public:
    int minCut(string s) {
        n = s.length();
        shift_left.clear();  // Must be called before use
        shift_left.resize(n);
        shift_right.clear();
        shift_right.resize(n);
        num_cuts.clear();
        num_cuts.resize(n + 1, n);
        for (int i = 0; i < n; ++i)
            if (i == 0 || s[i] != s[i - 1])
                shift_left[i] = 1;
            else
                shift_left[i] = shift_left[i - 1] + 1;
        for (int i = n - 1; i >= 0; --i)
            if (i == n - 1 || s[i] != s[i + 1])
                shift_right[i] = 1;
            else
                shift_right[i] = shift_right[i + 1] + 1;
        num_cuts[0] = 0;
        for (int i = 0; i < n; ++i)
            if (num_cuts[i] < n) {
                for (int j = i; j < n; ++j)
                    if (isPalindrome(s, i, j) &&
                        num_cuts[j + 1] > num_cuts[i] + 1) {
                        num_cuts[j + 1] = num_cuts[i] + 1;
                    }
            }
        return num_cuts[n] - 1;  // Mind to minus 1
    }
};
