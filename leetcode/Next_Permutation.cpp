class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int start = num.size() - 1;
        while (start > 0 && num[start - 1] >= num[start])
            --start;
        if (start > 0) {
            int pos_min_next = start;
            for (int i = start + 1; i < num.size(); ++i)
                if (num[i] > num[start - 1] && num[pos_min_next] > num[i])
                    pos_min_next = i;
            int tmp = num[pos_min_next];
            num[pos_min_next] = num[start - 1];
            num[start - 1] = tmp;
        }
        sort(num.begin() + start, num.end());
    }
};
