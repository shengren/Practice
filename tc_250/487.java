import java.util.*;

public class BunnyComputer {
    public int getMaximum(int[] pref, int k) {
        int res = 0;
        for (int i = 0; i <= k; ++i) {
            ArrayList<Integer> group = new ArrayList<Integer>();
            for (int j = i; j < pref.length; j += (k + 1)) {
                group.add(pref[j]);
            }
            res += solve(group);
        }
        return res;
    }

    int solve(ArrayList<Integer> group) {
        int[] best = new int[group.size() + 1];
        for (int i = 0; i < group.size(); ++i) {
            best[i + 1] = Math.max(best[i + 1], best[i]);
            if (i < group.size() - 1) {
                best[i + 2] = Math.max(best[i + 2], 
                                       best[i] + (int)group.get(i) + (int)group.get(i + 1));
            }
        }
        return best[group.size()];
    }
}