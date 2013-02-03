class Solution {
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    } 
public:
    void sortColors(int A[], int n) {
        int forward_idx = 0;
        int backward_idx = n - 1;
        while (forward_idx < backward_idx) {
            while (forward_idx < n && A[forward_idx] == 0)
                ++forward_idx;
            while (backward_idx >= 0 && A[backward_idx] == 2)
                --backward_idx;
            int mid_idx = forward_idx;
            while (mid_idx <= backward_idx && A[mid_idx] == 1)
                ++mid_idx;
            if (mid_idx > backward_idx)  // All the elements in the middle are 1
                break;
            if (A[mid_idx] == 0)
                swap(A[forward_idx], A[mid_idx]);
            else if (A[mid_idx] == 2)
                swap(A[backward_idx], A[mid_idx]);
        }
    }
};
