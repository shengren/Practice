import java.util.*;

public class Solution {
    public boolean isNumber(String s) {
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (!((c >= '0' && c <= '9')
                  || c == ' ' || c == '.'
                  || c == '+' || c == '-'
                  || c == 'E' || c == 'e'))
                return false;
        }
        try {
            double n = Double.parseDouble(s);
        } catch (Exception e) {
            return false;
        }
        return true;
    }
}
