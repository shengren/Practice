class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        vector<vector<int> > d;
        d.push_back(vector<int>(triangle.size()));
        d.push_back(vector<int>(triangle.size()));
        d[0][0] = triangle[0][0];
        for (int l = 2; l <= triangle.size(); ++l) {
            int p = l % 2;
            int q = 1 - p;
            for (int j = 0; j < l; ++j) {
                d[q][j] = 987654321;
                if (j < l - 1 && d[q][j] > d[p][j] + triangle[l - 1][j])
                    d[q][j] = d[p][j] + triangle[l - 1][j];
                if (j > 0 && d[q][j] > d[p][j - 1] + triangle[l - 1][j])
                    d[q][j] = d[p][j - 1] + triangle[l - 1][j];
            }
        }
        int f = 1 - triangle.size() % 2;
        int ret = 987654321;
        for (int i = 0; i < triangle.size(); ++i)
            if (ret > d[f][i])
                ret = d[f][i];
        return ret;
    }
};