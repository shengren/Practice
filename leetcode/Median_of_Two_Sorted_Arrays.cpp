class Solution {
    int binarySearch(int num[], int beg, int end, int target) {
        if (beg + 1 == end) {
            if (num[beg] > target)
                return beg - 1;
            else
                return beg;
        }
        int mid = (beg + end) / 2;
        if (num[mid] > target)
            return binarySearch(num, beg, mid, target);
        else
            return binarySearch(num, mid, end, target);
    }
    int find(int A[], int begA, int endA,
             int B[], int begB, int endB,
             int k) {
        if (begA == endA)
            return B[begB + k];
        if (begB == endB)
            return A[begA + k];
        if (begA + 1 == endA) {  // The if-else cannot handle this case
            int posB = binarySearch(B, begB, endB, A[begA]) + 1;
            // posB is just an offset. The base is begB.
            if (posB - begB == k)
                return A[begA];
            else if (posB - begB > k)
                return B[begB + k];
            else
                return B[begB + k - 1];
        }
        if (begB + 1 == endB) {
            int posA = binarySearch(A, begA, endA, B[begB]) + 1;
            // posA is an offset. The base is begA.
            if (posA - begA == k)
                return B[begB];
            else if (posA - begA > k)
                return A[begA + k];
            else
                return A[begA + k - 1];
        }
        int midA = (begA + endA) / 2;
        int midB = binarySearch(B, begB, endB, A[midA]) + 1;
        if (midA - begA + midB - begB > k)
            return find(A, begA, midA, B, begB, midB, k);
        else
            return find(A, midA, endA, B, midB, endB,
                        k - (midA - begA + midB - begB));
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 1) {
            // ((m + n) / 2)
            return find(A, 0, m, B, 0, n, (m + n) / 2);
        } else {
            // ((m + n) / 2 - 1) ((m + n) / 2)
            return 0.5 * (find(A, 0, m, B, 0, n, (m + n) / 2 - 1) + 
                          find(A, 0, m, B, 0, n, (m + n) / 2));
        }
    }
};
