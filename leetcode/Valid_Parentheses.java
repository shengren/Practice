import java.util.*;

public class Solution {
    public boolean isValid(String s) {
        Stack<Integer> sk = new Stack<Integer>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                sk.push(0);
            } else if (c == '[') {
                sk.push(1);
            } else if (c == '{') {
                sk.push(2);
            } else if (c == ')') {
                if (sk.size() == 0) return false;
                int t = sk.pop();
                if (t != 0) return false;
            } else if (c == ']') {
                if (sk.size() == 0) return false;
                int t = sk.pop();
                if (t != 1) return false;
            } else {
                if (sk.size() == 0) return false;
                int t = sk.pop();
                if (t != 2) return false;
            }
        }
        return sk.size() == 0;
    }
}
