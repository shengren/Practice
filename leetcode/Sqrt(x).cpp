class Solution {
    int find(int beg, int end, int target) {
        if (beg + 1 == end)
            return beg;
        long long mid = ((long long)beg + end) / 2;
        if (mid * mid > target)
            return find(beg, mid, target);
        else
            return find(mid, end, target);
    }
public:
    int sqrt(int x) {
        if (x < 2)
            return x;
        return find(1, x, x);
    }
};
