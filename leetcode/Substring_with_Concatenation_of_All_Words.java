import java.util.*;

public class Solution {
    int binarySearch(String[] L, int tp, String s) {
        int a = 0;
        int b = tp;
        while (a < b) {
            int m = (a + b) / 2;
            int cmp = s.compareTo(L[m]);
            if (cmp == 0) return m;
            else if (cmp < 0) b = m;
            else a = m + 1;
        }
        return -1;
    }
    int remove(String[] L, int tp, int r) {
        for (int i = r; i < tp - 1; ++i) L[i] = L[i + 1];
        return tp - 1;
    }
    public ArrayList<Integer> findSubstring(String S, String[] L) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        int n = L.length;
        int w = L[0].length();
        Arrays.sort(L);
        int tp = n;
        ArrayList<String> b = new ArrayList<String>();

        for (int j = 0; j < w; ++j) {
            for (int i = j; i + w <= S.length(); i += w) {
                if (i + w * tp > S.length()) break;
                String s = S.substring(i, i + w);
                boolean flag = false;
                int r = binarySearch(L, tp, s);
                if (r != -1) {
                    b.add(L[r]);
                    tp = remove(L, tp, r);
                    flag = true;
                }
                if (!flag) {
                    ListIterator<String> it = b.listIterator();
                    while (it.hasNext()) {  // b
                        String x = it.next();
                        if (s.equals(x)) {
                            String y = b.get(0);
                            while (!x.equals(y)) {
                                L[tp++] = y;
                                b.remove(0);
                                y = b.get(0);
                            }
                            Arrays.sort(L);
                            b.remove(0);
                            b.add(y);
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) {
                    if (tp == 0) {
                        ret.add(i - w * (n - 1));
                    }
                } else {
                    while (!b.isEmpty()) {
                        String y = b.get(0);
                        L[tp++] = y;
                        b.remove(0);
                    }
                    Arrays.sort(L);
                }
            }
            while (!b.isEmpty()) {
                String y = b.get(0);
                L[tp++] = y;
                b.remove(0);
            }
            Arrays.sort(L);
        }
        return ret;
    }
}
