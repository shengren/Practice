import java.util.*;

class Candidate {
    int val, num;
}

public class Solution {
    void search(Candidate[] cand, int num_cand, int target, int cur, int sum, ArrayList<Integer> in, ArrayList<ArrayList<Integer>> ret) {
        if (sum == target) {
            ret.add(new ArrayList<Integer>(in));
            return;
        }
        if (cur == num_cand) return;
        for (int i = 0; i <= cand[cur].num; ++i)
            if (sum + i * cand[cur].val <= target) {
                for (int k = 1; k <= i; ++k) in.add(cand[cur].val);
                search(cand, num_cand, target, cur + 1, sum + i * cand[cur].val, in, ret);
                for (int k = 1; k <= i; ++k) in.remove(in.size() - 1);
            }
    }
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        int num_cand = 0;
        Candidate[] cand = new Candidate[candidates.length];
        for (int i = 0; i < candidates.length; ++i)
            if (i == 0 || candidates[i] != candidates[i - 1]) {
                cand[num_cand] = new Candidate();
                cand[num_cand].val = candidates[i];
                cand[num_cand].num = 1;
                ++num_cand;
            } else {
                ++cand[num_cand - 1].num;
            }
        ArrayList<Integer> in = new ArrayList<Integer>();
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        search(cand, num_cand, target, 0, 0, in, ret);
        return ret;
    }
}
