class Solution {
    int num_row;
    int num_col;
    int compare(vector<vector<int> > &matrix, int idx, int target) {
        int ridx = idx / num_col;
        int cidx = idx % num_col;
        return matrix[ridx][cidx] - target;
    }
    bool binarySearch(vector<vector<int> > &matrix,
                       int beg, int end, int target) {
        if (beg == end)
            return false;
        if (beg + 1 == end)
            return compare(matrix, beg, target) == 0;
        int mid = (beg + end) / 2;
        int sign = compare(matrix, mid, target);
        if (sign == 0)
            return true;
        else if (sign < 0)
            return binarySearch(matrix, mid + 1, end, target);
        else
            return binarySearch(matrix, beg,     mid, target);
    }
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        num_row = matrix.size();
        if (num_row == 0)
            return false;
        num_col = matrix[0].size();
        if (num_col == 0)
            return false;
        return binarySearch(matrix, 0, num_row * num_col, target);
    }
};
