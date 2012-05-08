import java.util.*;

public class Solution {
    int find(String s, char c) {
        if (s.charAt(0) == c) return 0;
        if (s.length() > 1 && s.charAt(1) == c) return 1;
        return -1;
    }
    int convert(String s) {
        if (s.length() == 0) return 0;
        int k = find(s, 'M');
        if (k != -1) {
            if (k == 0) return 1000 + convert(s.substring(k + 1));
            else return 900 + convert(s.substring(k + 1));
        }
        k = find(s, 'D');
        if (k != -1) {
            if (k == 0) return 500 + convert(s.substring(k + 1));
            else return 400 + convert(s.substring(k + 1));
        }
        k = find(s, 'C');
        if (k != -1) {
            if (k == 0) return 100 + convert(s.substring(k + 1));
            else return 90 + convert(s.substring(k + 1));
        }
        k = find(s, 'L');
        if (k != -1) {
            if (k == 0) return 50 + convert(s.substring(k + 1));
            else return 40 + convert(s.substring(k + 1));
        }
        k = find(s, 'X');
        if (k != -1) {
            if (k == 0) return 10 + convert(s.substring(k + 1));
            else return 9;
        }
        k = find(s, 'V');
        if (k != -1) {
            if (k == 0) return 5 + convert(s.substring(k + 1));
            else return 4;
        }
        k = find(s, 'I');
        if (k != -1) return 1 + convert(s.substring(k + 1));
        return -123456;
    }
    public int romanToInt(String s) {
        return convert(s);
    }
}