import java.util.*;

class Chain {
    int p, q;
    int case_no;
}

public class DengklekMakingChains {
    public int maxBeauty(String[] chains) {
        Chain[] c = new Chain[chains.length];
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < chains.length; ++i) {
            c[i] = new Chain();
            if (chains[i].equals("...")) {
                c[i].case_no = 0;
            } else if (chains[i].charAt(0) == '.' && chains[i].charAt(2) == '.') {
                int t = chains[i].charAt(1) - '0';
                if (c1 < t) c1 = t;
                c[i].case_no = 1;
            } else if (chains[i].charAt(0) == '.') {
                int t = 0;
                if (chains[i].charAt(1) != '.') t += chains[i].charAt(1) - '0';
                t += chains[i].charAt(2) - '0';
                c[i].case_no = 2;
                c[i].q = t;
            } else if (chains[i].charAt(2) == '.') {
                int t = 0;
                if (chains[i].charAt(1) != '.') t += chains[i].charAt(1) - '0';
                t += chains[i].charAt(0) - '0';
                c[i].case_no = 3;
                c[i].p = t;
            } else if (chains[i].charAt(1) == '.') {
                c[i].case_no = 4;
                c[i].p = chains[i].charAt(0) - '0';
                c[i].q = chains[i].charAt(2) - '0';
            } else {
                c2 += (chains[i].charAt(0) - '0') + (chains[i].charAt(1) - '0') + (chains[i].charAt(2) - '0');
                c[i].case_no = 5;
            }
        }
        int best = 0;
        for (int i = 0; i < c.length; ++i) {
            if (c[i].case_no == 2) best = Math.max(best, c[i].q);
            if (c[i].case_no == 3) best = Math.max(best, c[i].p);
            if (c[i].case_no == 4) best = Math.max(best, Math.max(c[i].p, c[i].q));
        }
        for (int i = 0; i < c.length; ++i) {
            if (c[i].case_no == 2 || c[i].case_no == 4) {
                for (int j = 0; j < c.length; ++j) {
                    if (j != i && (c[j].case_no == 3 || c[j].case_no == 4)) {
                        best = Math.max(best, c[i].q + c[j].p);
                    }
                }
            }
        }
        c2 += best;
        return (c1 > c2) ? c1 : c2;
    }
}