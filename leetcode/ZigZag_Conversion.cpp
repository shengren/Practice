class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)
            return s;
        vector<vector<char> > char_sequences(nRows);
        bool downward = true;
        int r = 0;
        for (int i = 0; i < s.length(); ++i) {
            char_sequences[r].push_back(s[i]);
            if (downward) {
                if (r == nRows - 1) {
                    downward = false;
                    --r;
                } else {
                    ++r;
                }
            } else {
                if (r == 0) {
                    downward = true;
                    ++r;
                } else {
                    --r;
                }
            }
        }
        string zigzag = "";
        for (int i = 0; i < nRows; ++i)
            for (int j = 0; j < char_sequences[i].size(); ++j)
                zigzag += char_sequences[i][j];
        return zigzag;
    }
};
