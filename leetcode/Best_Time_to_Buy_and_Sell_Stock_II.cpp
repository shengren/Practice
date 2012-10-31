// Greedy

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int ret = 0;
        int pre_p = prices[0];
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > pre_p) {
                ret += prices[i] - pre_p;
                pre_p = prices[i];
            } else if (prices[i] < pre_p) {
                pre_p = prices[i];
            }
        return ret;
    }
};
