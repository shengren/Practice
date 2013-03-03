class Solution {
    int n;
    vector<vector<vector<string>>> partitions;
    bool isPalindrome(string s, int a, int b) {
        // More efficient if using cache
        while (a < b) {
            if (s[a] != s[b])
                return false;
            ++a;
            --b;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.length();
        partitions.clear();  // resize() does not do clear.
        partitions.resize(n + 1);
        partitions[0].push_back(vector<string>());
        for (int i = 0; i < n; ++i)
            if (!partitions[i].empty()) {
                for (int j = i; j < n; ++j)
                    if (isPalindrome(s, i, j)) {
                        string p = s.substr(i, j - i + 1);
                        for (int k = 0; k < partitions[i].size(); ++k) {
                            partitions[j + 1].push_back(partitions[i][k]);
                            partitions[j + 1].back().push_back(p);
                        }
                    }
            }
        return partitions[n];
    }
};
