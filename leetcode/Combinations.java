import java.util.*;

public class Solution {
    void solve(int n, int k, int c, ArrayList<Integer> comb, ArrayList<ArrayList<Integer>> res) {
        int h = comb.size();
        if (h == k) {
            ArrayList<Integer> r = new ArrayList<Integer>(comb);
            res.add(r);
            return;
        }
        for (int i = c; n - i >= k - h - 1; ++i) {
            comb.add(i);
            solve(n, k, i + 1, comb, res);
            comb.remove(comb.size() - 1);
        }
    }
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> comb = new ArrayList<Integer>();
        solve(n, k, 1, comb, ret);
        return ret;
    }
}
