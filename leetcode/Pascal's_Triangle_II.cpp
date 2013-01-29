class Solution {
public:
    vector<int> getRow(int rowIndex) {  // rowIndex is 0-based
        vector<int> row;
        row.push_back(1);
        for (int r = 1; r <= rowIndex; ++r) {
            int pre = 1;
            for (int i = 1; i < r; ++i) {
                int cur = pre + row[i];
                pre = row[i];
                row[i] = cur;
            }
            row.push_back(1);
        }
        return row;
    }
};
