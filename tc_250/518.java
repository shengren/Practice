import java.util.*;

public class LargestSubsequence {
    public String getLargest(String s) {
        StringBuffer ret = new StringBuffer("");
        while (s.length() > 0) {
            for (int i = 25; i >= 0; --i) {
                int index = s.indexOf(i + 'a');
                if (index != -1) {
                    ret.append(s.charAt(index));
                    s = s.substring(index + 1);
                    break;
                }
            }
        }
        return ret.toString();
    }
}