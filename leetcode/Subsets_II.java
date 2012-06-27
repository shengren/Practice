import java.util.*;

public class Solution {
    void Solve(int[] x, int[] c, int n, int k, ArrayList<Integer> cur,
               ArrayList<ArrayList<Integer>> ret) {
        if (k == n) {
            ret.add(new ArrayList<Integer>(cur));
            return;
        }
        Solve(x, c, n, k + 1, cur, ret);
        for (int i = 0; i < c[k]; ++i) {
            cur.add(x[k]);
            Solve(x, c, n, k + 1, cur, ret);
        }
        for (int i = 0; i < c[k]; ++i) {
            cur.remove(cur.size() - 1);
        }
    }
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        Arrays.sort(num);
        int[] x = new int[num.length];
        int[] c = new int[num.length];
        int n = 0;
        for (int i = 0; i < num.length; ++i) {
            if (i == 0 || num[i] != num[i - 1]) {
                ++n;
                x[n - 1] = num[i];
                c[n - 1] = 1;
            } else {
                ++c[n - 1];
            }
        }
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> cur = new ArrayList<Integer>();
        Solve(x, c, n, 0, cur, ret);
        return ret;
    }
}
