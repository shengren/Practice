import java.util.*;

public class Solution {
    private void Restore(String r, int k, String c, ArrayList<String> res) {
        if (k == 4) {
            if (r.length() == 0) {
                res.add(c);
            }
            return;
        }
        if (r.length() == 0) return;
        if (r.length() >= 1) {
            String nc = new String(c);
            nc += r.substring(0, 1);
            if (k != 3) nc += ".";
            Restore(r.substring(1), k + 1, nc, res);
        }
        if (r.length() >= 2 && r.charAt(0) != '0') {
            String nc = new String(c);
            nc += r.substring(0, 2);
            if (k != 3) nc += ".";
            Restore(r.substring(2), k + 1, nc, res);
        }
        if (r.length() >= 3 && r.charAt(0) != '0') {
            int x = Integer.parseInt(r.substring(0, 3));
            if (x <= 255) {
                String nc = new String(c);
                nc += r.substring(0, 3);
                if (k != 3) nc += ".";
                Restore(r.substring(3), k + 1, nc, res);
            }
        }
    }
    public ArrayList<String> restoreIpAddresses(String s) {
        ArrayList<String> ret = new ArrayList<String>();
        Restore(s, 0, "", ret);
        return ret;
    }
}

