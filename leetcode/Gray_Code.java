import java.util.*;

public class Solution {
    public ArrayList<Integer> grayCode(int n) {
        ArrayList<Integer> ret = new ArrayList<Integer>();
        boolean[] in = new boolean[1 << n];
        int x = 0;
        ret.add(0);
        in[0] = true;
        while (ret.size() < (1 << n)) {
            for (int i = 0; i < n; ++i) {
                int nx = x ^ (1 << i);
                if (!in[nx]) {
                    ret.add(nx);
                    in[nx] = true;
                    x = nx;
                    break;
                }
            }
        }
        return ret;
    }
}