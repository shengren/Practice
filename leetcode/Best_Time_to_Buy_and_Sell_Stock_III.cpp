class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int num_days = prices.size();
        if (num_days < 2)
            return 0;
            
        vector<int> max_profit_forward(num_days);
        max_profit_forward[0] = 0;
        int min_price_ahead = prices[0];
        for (int i = 1; i < num_days; ++i) {
            max_profit_forward[i] = max_profit_forward[i - 1];
            if (max_profit_forward[i] < prices[i] - min_price_ahead)
                max_profit_forward[i] = prices[i] - min_price_ahead;
            if (min_price_ahead > prices[i])
                min_price_ahead = prices[i];
        }
        
        vector<int> max_profit_reverse(num_days);
        max_profit_reverse[num_days - 1] = 0;
        int max_price_behind = prices[num_days - 1];
        for (int i = num_days - 2; i >= 0; --i) {
            max_profit_reverse[i] = max_profit_reverse[i + 1];
            if (max_profit_reverse[i] < max_price_behind - prices[i])
                max_profit_reverse[i] = max_price_behind - prices[i];
            if (max_price_behind < prices[i])
                max_price_behind = prices[i];
        }
        
        int max_profit = 0;
        for (int i = 1; i < num_days; ++i) {
            int p = max_profit_forward[i];
            if (i < num_days - 2)
                p += max_profit_reverse[i + 1];
            if (max_profit < p)
                max_profit = p;
        }
        
        return max_profit;
    }
};
