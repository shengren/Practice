class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > tri;
        for (int i = 1; i <= numRows; ++i) {
            vector<int> new_row;
            new_row.push_back(1);
            for (int j = 2; j < i; ++j)
                new_row.push_back(tri[i - 2][j - 2] + tri[i - 2][j - 1]);
            if (i > 1)
                new_row.push_back(1);
            tri.push_back(new_row);
        }
        return tri;
    }
};
