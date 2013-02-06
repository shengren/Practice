class Solution {
    int binarySearch(int A[], int first, int last, int target) {
        if (first == last) {
            if (A[first] == target)
                return first;
            return -1;
        }
        if (first + 1 == last) {
            if (A[first] == target)
                return first;
            return binarySearch(A, last, last, target);
        }
        int middle = (first + last) / 2;
        if (A[middle] == target)
            return middle;
        // Only one half can be regular
        if (A[first] <= A[middle - 1])  // First half is regular
            if (A[first] <= target && A[middle - 1] >= target)
                return binarySearch(A, first, middle - 1, target);
            else
                return binarySearch(A, middle + 1, last, target);
        else  // Second half is regular
            if (A[middle + 1] <= target && A[last] >= target)
                return binarySearch(A, middle + 1, last, target);
            else
                return binarySearch(A, first, middle - 1, target);
    }
public:
    int search(int A[], int n, int target) {
        if (n < 1)
            return -1;
        return binarySearch(A, 0, n - 1, target);
    }
};
