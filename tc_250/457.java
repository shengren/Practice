import java.util.*;

public class TheTriangleBothDivs {
    String time;
    public String fix(String time) {
        this.time = time;
        String res = "";
        for (int i = 0; i <= 23; ++i)
            for (int j = 0; j <= 59; ++j)
                for (int k = -9; k <= 9; ++k) {
                    if (isOK(i, j, k)) {
                        String gt = GMT(i, j, k);
                        if (res.equals("") || res.compareTo(gt) > 0) res = gt;
                    }
                }
        return res;
    }

    boolean isOK(int h, int m, int z) {
        String hs = time.substring(0, 2);
        String ms = time.substring(3, 5);
        String zs = time.substring(9);
        if (!isSatisfied(h, hs)) return false;
        if (!isSatisfied(m, ms)) return false;
        if (zs.charAt(0) == '+') {
            return (z >= 0 && isSatisfied(z, zs.substring(1)));
        }
        else if (zs.charAt(0) == '-') {
            return (z < 0 && isSatisfied(-z, zs.substring(1)));
        }
        else {
            if (zs.charAt(1) == '?') return true;
            return isSatisfied(Math.abs(z), zs.substring(1));
        }
    }

    boolean isSatisfied(int n, String s) {
        for (int i = s.length() - 1; i >= 0; --i) {
            if ((s.charAt(i) != '?') && (s.charAt(i) != '0' + n % 10)) return false;
            n /= 10;
        }
        return true;
    }

    String GMT(int h, int m, int z) {
        h = (h - z + 24) % 24;
        return String.format("%02d:%02d", h, m);
    }
}