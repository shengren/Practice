public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0;
        
        int[] best = new int[prices.length];
        best[0] = 0;
        int minp = prices[0];
        for (int i = 1; i < prices.length; ++i) {
            best[i] = Math.max(best[i - 1], prices[i] - minp);
            minp = Math.min(minp, prices[i]);
        }
        
        int ret = best[best.length - 1];
        
        minp = prices[0];
        int pos = 0;
        for (int i = 1; i < prices.length; ++i) {
            for (int j = pos; j < i; ++j) {
                int x = 0;
                if (j > 0) x += best[j - 1];
                x += prices[i] - prices[j];
                if (ret < x) ret = x;
            }
            if (minp >= prices[i]) {
                minp = prices[i];
                pos = i;
            }
        }
        
        return ret;
    }
}
