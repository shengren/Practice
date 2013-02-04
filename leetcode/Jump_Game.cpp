class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        int rightmost = 0;
        for (int i = 0; i < n - 1; ++i)
            if (i <= rightmost) {  // reachable
                rightmost = max(rightmost, i + A[i]);
                if (rightmost >= n - 1)
                    return true;
            } else {
                return false;
            }
        return false;
    }
};
