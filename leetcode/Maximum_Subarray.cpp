typedef pair<int, int> Segment;

class Solution {
    vector<int> prefix_sum;
    int getSum(Segment seg) {
        if (seg.first == 0)
            return prefix_sum[seg.second];
        return prefix_sum[seg.second] - prefix_sum[seg.first - 1];
    }
    void find(int beg, int end,
              Segment &from_left, Segment &from_right, Segment &best) {
        if (beg == end) {
            from_left = from_right = best = make_pair(beg, end);
            return;
        }
        
        int mid = (beg + end) / 2;
        Segment L_from_left, L_from_right, L_best;
        Segment R_from_left, R_from_right, R_best;
        find(beg,     mid, L_from_left, L_from_right, L_best);
        find(mid + 1, end, R_from_left, R_from_right, R_best);
        
        from_left = L_from_left;
        // Use the entire left half, not just L_from_left
        if (getSum(from_left) <=
            getSum(make_pair(beg, mid)) + getSum(R_from_left))
            from_left.second = R_from_left.second;
        
        from_right = R_from_right;
        // Use the entire right half, not just R_from_right
        if (getSum(from_right) <=
            getSum(make_pair(mid + 1, end)) + getSum(L_from_right))
            from_right.first = L_from_right.first;
        
        best = (getSum(L_best) > getSum(R_best)) ? L_best : R_best;
        if (getSum(best) < getSum(L_from_right) + getSum(R_from_left))
            best = make_pair(L_from_right.first, R_from_left.second);
    }
public:
    // Divide & Conquer
    int maxSubArray(int A[], int n) {
        prefix_sum.resize(n);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i] = A[i];
            if (i > 0)
                prefix_sum[i] += prefix_sum[i - 1];
        }
        Segment from_left, from_right, best;
        find(0, n - 1, from_left, from_right, best);
        return getSum(best);
    }
};
