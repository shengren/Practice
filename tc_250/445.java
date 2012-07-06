/*
LSR 11-09-16

Guessed the answer. Incomplete proof: All input points have integer coordinates. Shifting between 0 and 0.5 will not
change the order but the value can be optimal only when divided by 0.5.
*/

import java.util.*;

public class TheNewHouseDivOne {
    int[] x;
    int[] y;
    int k, n;

    public double distance(int[] x, int[] y, int k) {
        this.x = x;
        this.y = y;
        this.k = k;
        n = x.length;

        double ret = Double.MAX_VALUE;
        for (double i = -50.0; i <= 50.0; i += 0.5) {
            for (double j = -50.0; j <= 50.0; j += 0.5) {
                double kth = calculateKth(i, j);
                ret = Math.min(ret, kth);
            }
        }
        return ret;
    }

    double calculateKth(double cx, double cy) {
        double[] d = new double[n];
        for (int i = 0; i < n; ++i) {
            d[i] = getManhattanDistance(cx, cy, x[i], y[i]);
        }
        Arrays.sort(d);
        return d[k - 1];
    }

    double getManhattanDistance(double ax, double ay, double bx, double by) {
        return Math.abs(ax - bx) + Math.abs(ay - by);
    }
}