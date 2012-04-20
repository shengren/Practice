import java.util.*;

public class Solution {
    void dfs(String digits, int k, String[] map, String s, ArrayList<String> res) {
        if (k == digits.length()) {
            res.add(s);
            return;
        }
        int idx = digits.charAt(k) - '0' - 2;
        for (int i = 0; i < map[idx].length(); ++i) {
            dfs(digits, k + 1, map, s + map[idx].charAt(i), res);
        }
    }
    public ArrayList<String> letterCombinations(String digits) {
        String[] map = new String[8];
        map[0] = "abc";
        map[1] = "def";
        map[2] = "ghi";
        map[3] = "jkl";
        map[4] = "mno";
        map[5] = "pqrs";
        map[6] = "tuv";
        map[7] = "wxyz";
        ArrayList<String> ret = new ArrayList<String>();
        dfs(digits, 0, map, "", ret);
        return ret;       
    }
}