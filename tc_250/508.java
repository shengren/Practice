public class DivideAndShift {
    public int getLeast(int N, int M) {
        --M;  // for convenience
        int ret = Integer.MAX_VALUE;  // initialization using infinite
        for (int last = 1; last <= N; ++last) {
            if (N % last != 0) continue;
            int cur = numDivisors(N / last) + Math.min(M % last, last - M % last);
            ret = Math.min(ret, cur);  // instead of compare and update
        }
        return ret;
    }

    private int numDivisors(int x) {
        int ret = 0;
        for (int i = 2; i * i <= x; ++i) {
            while (x % i == 0) {
                x /= i;
                ++ret;
            }
        }
        if (x > 1) ++ret;
        return ret;
    }
}