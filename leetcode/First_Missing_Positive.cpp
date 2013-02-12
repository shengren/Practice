class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int num_positive = n;
        for (int i = 0; i < num_positive;)
            if (A[i] <= 0) {
                --num_positive;
                int tmp = A[i];
                A[i] = A[num_positive];
                A[num_positive] = tmp;
            } else {
                ++i;
            }
        for (int i = 0; i < num_positive;)
            if (A[i] != i + 1 && 
                A[i] <= num_positive && 
                A[A[i] - 1] != A[i]) {  // Missed this condition at first
                int tmp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = tmp;
            } else {
                ++i;
            }
        for (int i = 0; i < num_positive; ++i)
            if (A[i] != i + 1)
                return i + 1;
        return num_positive + 1;
    }
};
