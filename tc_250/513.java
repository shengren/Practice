public class YetAnotherIncredibleMachine {
    final long mod = 1000000009L;

    public int countWays(int[] platformMount, int[] platformLength, int[] balls) {
        int n = platformMount.length;
        long res = 1;
        for (int i = 0; i < n; ++i) {
            long pass = 0;
            for (int j = platformMount[i] - platformLength[i]; j <= platformMount[i]; ++j)
                if (ok(j, j + platformLength[i], balls))
                    ++pass;
            res = (res * pass) % mod;
        }
        return (int)res;
    }

    boolean ok(int left, int right, int[] balls) {
        for (int i = 0; i < balls.length; ++i)
            if (balls[i] >= left && balls[i] <= right)
                return false;
        return true;
    }
}