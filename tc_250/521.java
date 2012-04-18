import java.util.*;

public class MissingParentheses {
    public int countCorrections(String par) {
        int ct = 0;
        int ret = 0;
        for (int i = 0; i < par.length(); ++i) {
            if (par.charAt(i) == '(') {
                ++ct;
            } else {
                if (ct == 0) {
                    ++ret;
                } else {
                    --ct;
                }
            }
        }
        return ret + ct;
    }
}