public class TheAlmostLuckyNumbersDivOne {
    long a, b, total;

    public long find(long a, long b) {
        this.a = a;
        this.b = b;
        total = 0;
        backtrack(0, true);

        return total;
    }

    void backtrack(long x, boolean canBad) {
        if (x <= b) {
            if (x >= a) ++total;
            backtrack(x * 10 + 4, canBad);
            backtrack(x * 10 + 7, canBad);
            if (canBad) {
                for (int i = 1; i < 10; ++i) {
                    if (i == 4 || i == 7) continue;
                    backtrack(x * 10 + i, false);
                }
                if (x != 0) backtrack(x * 10, false);
            }
        }
    }
}