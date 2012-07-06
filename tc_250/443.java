import java.util.*;

public class CirclesCountry {
    int numCircle;
    Circle[] c;

    public int leastBorders(int[] X, int[] Y, int[] R, int x1, int y1, int x2, int y2) {
        numCircle = X.length;
        c = new Circle[numCircle];
        for (int i = 0; i < numCircle; ++i) {
            c[i] = new Circle(X[i], Y[i], R[i]);
        }
        Arrays.sort(c);

        for (int i = 0; i < numCircle; ++i)
            for (int j = i + 1; j < numCircle; ++j)
                if (c[j].contains(c[i])) {
                    c[i].p = j;
                    break;
                }

        int p1 = -1, p2 = -1;
        for (int i = 0; i < numCircle; ++i)
            if (c[i].contains(x1, y1)) {
                p1 = i;
                break;
            }
        for (int i = 0; i < numCircle; ++i)
            if (c[i].contains(x2, y2)) {
                p2 = i;
                break;
            }
            
        System.out.printf("%d %d%n", p1, p2);

        ArrayList<Integer> path = new ArrayList<Integer>();
        path.add(p1);
        while (p1 != -1) {
            p1 = c[p1].p;
            path.add(p1);
        }

        int ret = 0;
        while (true) {
            int len1 = path.indexOf(p2);
            if (len1 == -1) {
                p2 = c[p2].p;
                ++ret;
            } else {
                ret += len1;
                break;
            }
        }

        return ret;
    }
}

class Circle implements Comparable<Circle> {
    int x, y, r, p;

    public Circle(int x, int y, int r) {
        this.x = x;
        this.y = y;
        this.r = r;
        p = -1;
    }

    public boolean contains(Circle o) {
        if (r <= o.r) return false;
        //return distance(x, y, o.x, o.y) < r;
        return contains(o.x, o.y);
    }

    public boolean contains(int ox, int oy) {
        return distance(x, y, ox, oy) < r;
    }

    double distance(int ax, int ay, int bx, int by) {
        double ret = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        return Math.sqrt(ret);
    }
    
    public int compareTo(Circle o) {
        return r - o.r;
    }
}