import java.util.*;

public class IncredibleMachine {
    int n;
    double[] sinA;
    double[] len;

    public double gravitationalAcceleration(int[] x, int[] y, int T) {
        n = x.length - 1;
        sinA = new double[n];
        len = new double[n];
        for (int i = 0; i < n; ++i) {
            len[i] = calculateDistance(x[i], y[i], x[i + 1], y[i + 1]);
            sinA[i] = (y[i] - y[i + 1]) / len[i];
        }

        double a = 0.0;
        double b = 30000.0;
        while (true) {
            double m = (a + b) * 0.5;
            double time = apply(m);
            if (Math.abs(time - T) < 1e-12) return m;
            else if (time > T) a = m;
            else b = m;
        }
    }

    double apply(double g) {
        double v = 0.0;
        double totalTime = 0.0;
        for (int i = 0; i < n; ++i) {
            double t = calculateTime(v, g * sinA[i], len[i]);
            v += g * sinA[i] * t;
            totalTime += t;
        }
        return totalTime;
    }

    double calculateDistance(int ax, int ay, int bx, int by) {
        double ret = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        return Math.sqrt(ret);
    }

    double calculateTime(double v, double a, double d) {
        return (Math.sqrt(v * v + 2.0 * a * d) - v) / a;
    }
}