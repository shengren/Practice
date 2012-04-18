import java.util.*;

public class Solution {
    void search(int[] cand, int target, int cur, int sum, ArrayList<Integer> in, ArrayList<ArrayList<Integer>> ret) {
        if (sum == target) {
            ret.add(new ArrayList<Integer>(in));
            return;
        }
        for (int i = cur; i < cand.length; ++i)
            if (sum + cand[i] <= target) {
                in.add(cand[i]);
                search(cand, target, i, sum + cand[i], in, ret);
                in.remove(in.size() - 1);
            }
    }
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(candidates);
        ArrayList<Integer> in = new ArrayList<Integer>();
        search(candidates, target, 0, 0, in, ret);
        return ret;
    }
}
