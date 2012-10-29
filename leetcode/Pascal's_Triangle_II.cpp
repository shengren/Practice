class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        ret.push_back(1);
        for (int r = 1; r <= rowIndex; ++r) {
            int pre = 1;
            for (int i = 1; i < r; ++i) {
                int cur = pre + ret[i];
                pre = ret[i];
                ret[i] = cur;
            }
            ret.push_back(1);
        }
        return ret;
    }
};
