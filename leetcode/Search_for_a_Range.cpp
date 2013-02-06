class Solution {
    int binarySearch(int A[], int beg, int end, int target, bool accept_equal) {
        if (beg + 1 == end) {
            if (A[beg] > target || (accept_equal && A[beg] == target))
                return beg - 1;
            else
                return beg;
        }
        int mid = (beg + end) / 2;
        if (A[mid] > target || (accept_equal && A[mid] == target))
            return binarySearch(A, beg, mid, target, accept_equal);
        else
            return binarySearch(A, mid, end, target, accept_equal);
    }
public:
    vector<int> searchRange(int A[], int n, int target) {
        int first_pos = binarySearch(A, 0, n, target, true) + 1;
        int last_pos  = binarySearch(A, 0, n, target, false);
        vector<int> range(2, -1);
        if (first_pos <= last_pos) {
            range[0] = first_pos;
            range[1] = last_pos;
        }
        return range;
    }
};
