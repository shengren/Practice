class Solution {
public:
    int trap(int A[], int n) {
        int water = 0;
        for (int i = 1; i < n - 1; ++i) {
            int left_bound = -1;
            int j = i - 1;
            while (j >= 0) {
                if (A[j] > A[i] && (left_bound == -1 || A[j] > A[left_bound]))
                    left_bound = j;
                --j;
            }
            int right_bound = -1;
            j = i + 1;
            while (j < n) {
                if (A[j] > A[i] && (right_bound == -1 || A[j] > A[right_bound]))
                    right_bound = j;
                ++j;
            }
            if (left_bound != -1 && right_bound != -1)
                water += min(A[left_bound], A[right_bound]) - A[i];
        }
        return water;
    }
};
