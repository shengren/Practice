public class TheBoredomDivOne {
    public double find(int n, int m) {
        int t = n + m;
        double[] F = new double[t + 1];
        F[t] = 0;
        F[t - 1] = (double)t / 2;
        for (int x = t - 2; x >= n; --x) {
            double p0 = (double)(x * (x - 1)) / (double)(t * (t - 1));
            double p2 = (double)((t - x) * (t - x - 1)) / 
                        (double)(t * (t - 1));
            double p1 = 1 - p0 - p2;
            F[x] = (1 + p1 * F[x + 1] + p2 * F[x + 2]) / (1 - p0);
        }
        return F[n];
    }
}