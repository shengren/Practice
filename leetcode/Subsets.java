import java.util.*;

public class Solution {
    void generate(int k, int[] S, ArrayList<Integer> s, ArrayList<ArrayList<Integer>> res) {
        ArrayList<Integer> x = new ArrayList<Integer>(s);
        res.add(x);
        if (k == S.length) return;
        for (int i = k; i < S.length; ++i) {
            s.add(S[i]);
            generate(i + 1, S, s, res);
            s.remove(s.size() - 1);
        }
    }
    public ArrayList<ArrayList<Integer>> subsets(int[] S) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> s = new ArrayList<Integer>();
        generate(0, S, s, ret);
        return ret;
    }
}