public class TheNumbersWithLuckyLastDigit {
    public int find(int n) {
        int[] twenty = new int[14];
        for (int i = 0; i <= 13; ++i) twenty[i] = -1;
        twenty[0] = 0;
        twenty[4] = 1;
        twenty[7] = 1;
        twenty[8] = 2;
        twenty[11] = 2;
        twenty[12] = 3;
        return solve(n, twenty);
    }

    private int solve(int n, int[] twenty) {
        if (n <= 13) return twenty[n];

        int next = n / 10 * 10;
        if (n % 10 >= 7) next += 7;
        else if (n % 10 >= 4) next += 4;
        else next -= 3;

        while (true) {
            int ret = solve(n - next, twenty);
            if (ret != -1) return (ret + 1);
            if (next % 10 == 7) next -= 3;
            else next -= 7;
        }
    }
}