class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int new_n = 0;
        int current_val = numeric_limits<int>::min();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != current_val) {
                A[new_n++] = current_val = A[i];
                count = 1;
            } else {
                ++count;
                if (count == 2)
                    A[new_n++] = A[i];
            }
        }
        return new_n;
    }
};
