class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        for (int i = 1; i <= numRows; ++i) {
            if (i == 1) {
                vector<int> r1;
                r1.push_back(1);
                ret.push_back(r1);
            } else if (i == 2) {
                vector<int> r2;
                r2.push_back(1);
                r2.push_back(1);
                ret.push_back(r2);
            } else {
                vector<int> cr;
                for (int j = 0; j < i; ++j) {
                    if (j == 0 || j == i - 1) {
                        cr.push_back(1);
                    } else {
                        cr.push_back(ret[i - 2][j - 1] + ret[i - 2][j]);
                    }
                }
                ret.push_back(cr);
            }
        }        
        return ret;
    }
};
