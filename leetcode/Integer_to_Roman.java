import java.util.*;

public class Solution {
    String convert(int n) {
        if (n >= 1000) {
            String pre = "";
            int c = n / 1000;
            while (c > 0) {
                pre += "M";
                --c;
            }
            return pre + convert(n % 1000);
        }
        if (n >= 900) return "CM" + convert(n - 900);
        if (n >= 500) {
            return "D" + convert(n - 500);
        }
        if (n >= 400) {
            return "CD" + convert(n - 400);
        }
        if (n >= 100) {
            String pre = "";
            int c = n / 100;
            while (c > 0) {
                pre += "C";
                --c;
            }
            return pre + convert(n % 100);
        }
        if (n >= 90) {
            return "XC" + convert(n - 90);
        }
        if (n >= 50) {
            return "L" + convert(n - 50);
        }
        if (n >= 40) {
            return "XL" + convert(n - 40);
        }
        if (n >= 10) {
            String pre = "";
            int c = n / 10;
            while (c > 0) {
                pre += "X";
                --c;
            }
            return pre + convert(n % 10);
        }
        if (n == 9) return "IX";
        if (n >= 5) return "V" + convert(n - 5);
        if (n == 4) return "IV";
        if (n > 0) {
            String s = "";
            int c = n;
            while (c > 0) {
                s += "I";
                --c;
            }
            return s;
        }
        return "";
    }
    public String intToRoman(int num) {
        return convert(num);
    }
}
