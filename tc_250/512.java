public class MysteriousRestaurant {
    String[] prices;
    int numDay, numDish, budget;

    public int maxDays(String[] prices, int budget) {
        this.prices = prices;
        this.budget = budget;
        numDay = prices.length;
        numDish = prices[0].length();

        for (int i = numDay; i >= 1; --i)
            if (ok(i)) return i;

        return 0;
    }

    boolean ok(int day) {
        int money = budget;
        for (int i = 0; i < 7; ++i) {
            int cheapest = Integer.MAX_VALUE;
            for (int j = 0; j < numDish; ++j) {
                int sum = 0;
                for (int d = i; d < day; d += 7)
                    sum += convert(prices[d].charAt(j));
                cheapest = Math.min(cheapest, sum);
            }
            money -= cheapest;
        }
        return (money >= 0);
    }

    int convert(char c) {
        if (Character.isDigit(c)) return c - '0';
        if (Character.isUpperCase(c)) return c - 'A' + 10;
        return c - 'a' + 36;
    }
}