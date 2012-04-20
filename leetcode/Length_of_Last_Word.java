import java.util.*;

public class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        int o = s.lastIndexOf(' ');
        if (o == -1) return s.length();
        return s.length() - 1 - o;       
    }
}