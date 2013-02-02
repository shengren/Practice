class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 + n2 != s3.length())
            return false;
        // Create a (n1 + 1)-by-(n2 + 1) boolean matrix initialized to false
        vector<vector<bool> > d(n1 + 1, vector<bool>(n2 + 1, false));
        d[0][0] = true;
        for (int i = 0; i < s3.length(); ++i)
            for (int j = 0; j <= i; ++j)
                // d[j][i - j] must exist
                if (j <= n1 && i - j <= n2 && d[j][i - j]) {
                    // s1[j] must exist
                    if (j < n1 && s1[j] == s3[i])
                        d[j + 1][i - j] = true;
                    // s2[i - j] must exist
                    if (i - j < n2 && s2[i - j] == s3[i])
                        d[j][i - j + 1] = true;
                }
        return d[n1][n2];
    }
};
