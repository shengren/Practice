class Solution {
    void swap(int &x, int &y) {
        int t = x;
        x = y;
        y = t;
    }
public:
    void merge(int A[], int m, int B[], int n) {
        // Mind this case
        if (n == 0)
            return;
        int a = 0;
        while (a < m) {
            if (A[a] <= B[0]) {
                ++a;
            } else {
                swap(A[a], B[0]);
                int b = 0;
                while (b < n - 1 && B[b] > B[b + 1]) {
                    swap(B[b], B[b + 1]);
                    ++b;
                }
            }
        }
        // Copy the largest n elements to A
        for (int i = 0; i < n; ++i)
            A[m + i] = B[i];
    }
};
