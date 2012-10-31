class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int ret = 0;
        int min_p = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - min_p > ret)
                ret = prices[i] - min_p;
            if (min_p > prices[i])
                min_p = prices[i];
        }
        return ret;
    }
};
