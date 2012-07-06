import java.util.*;

public class Inequalities {
    String[] ie;
    public int maximumSubset(String[] inequalities) {
        ie = inequalities;
        int ret = check(-1, false);
        for (int i = 0; i <= 1000; ++i) {
            ret = Math.max(ret, check(i, true));
            ret = Math.max(ret, check(i, false));
        }
        return ret;
    }

    int check(int x, boolean isEqual) {
        int ret = 0;
        for (int i = 0; i < ie.length; ++i) {
            if (isSatisfied(x, isEqual, ie[i].split(" "))) {
                ++ret;
            }
        }
        return ret;
    }

    boolean isSatisfied(int x, boolean isEqual, String[] e) {
        int c = Integer.parseInt(e[2]);
        if (e[1].equals("<")) {
            return x < c;
        }
        else if (e[1].equals("<=")) {
            if (isEqual) return x <= c;
            else return x < c;
        }
        else if (e[1].equals("=")) {
            return (isEqual && x == c);
        }
        else if (e[1].equals(">=")) {
            return x >= c;
        }
        else /*if (e[1] == ">")*/ {
            if (isEqual) return x > c;
            else return x >= c;
        }
    }
}