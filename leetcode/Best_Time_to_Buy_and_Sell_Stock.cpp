class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2)
      return 0;
    int max_profit = 0;
    int min_price_ahead = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (max_profit < prices[i] - min_price_ahead)
        max_profit = prices[i] - min_price_ahead;
      if (min_price_ahead > prices[i])
        min_price_ahead = prices[i];
    }
    return max_profit;
  }
};
