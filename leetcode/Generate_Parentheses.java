import java.util.*;

public class Solution {
    void solve(int rest, int matching, String s, ArrayList<String> res) {
        if (rest == 0 && matching == 0) {
            res.add(s);
            return;
        }
        if (rest > 0) solve(rest - 1, matching + 1, s + "(", res);
        if (matching > 0) solve(rest, matching - 1, s + ")", res);
    }
    public ArrayList<String> generateParenthesis(int n) {
        ArrayList<String> ret = new ArrayList<String>();
        solve(n - 1, 1, "(", ret);
        return ret;
    }
}
