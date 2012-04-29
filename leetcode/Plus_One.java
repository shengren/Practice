import java.util.*;

public class Solution {
    public int[] plusOne(int[] digits) {
        int a = 1;
        for (int i = digits.length - 1; i >= 0; --i) {
            int s = digits[i] + a;
            digits[i] = s % 10;
            a = s / 10;
        }
        if (a == 0) return digits;
        int[] res = new int[digits.length + 1];
        res[0] = a;
        System.arraycopy(digits, 0, res, 1, digits.length);
        return res;
    }
}
