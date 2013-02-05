class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2)
            return 0;
        vector<int> num_jump(n, -1);
        num_jump[0] = 0;
        int rightmost = 0;
        for (int i = 0; i < n - 1; ++i)
            if (rightmost < i + A[i]) {
                for (; rightmost + 1 <= i + A[i] && rightmost + 1 < n;)
                    num_jump[++rightmost] = num_jump[i] + 1;
                if (rightmost == n - 1)
                    return num_jump[n - 1];
            }
        return -1;
    }
};
