class Solution {
    int binarySearch(int A[], int beg, int end, int target) {
        if (beg + 1 == end) {
            if (A[beg] >= target)
                return beg - 1;
            else
                return beg;
        }
        int mid = (beg + end) / 2;
        if (A[mid] >= target)
            return binarySearch(A, beg, mid, target);
        else
            return binarySearch(A, mid, end, target);
    }
public:
    int searchInsert(int A[], int n, int target) {
        return binarySearch(A, 0, n, target) + 1;
    }
};
