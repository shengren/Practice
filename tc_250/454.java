import java.util.*;

public class DoubleXor {
    public int calculate(int N) {
    	if (N <= 9) return d(N);
        int last = N % 10;
        int ret = d(last);
        if (N / 10 % 2 == 1) {
            ret = d2(ret);
        }
        else {
            ret = d2(d2(ret));
        }
        if (last % 2 == 0) {
            ret = f(N / 10) * 10 + ret;
        }
        return ret;
    }

    int d(int n) {
        int c = n;
        for (int i = n - 1; i >= 0; --i) {
            c = (c ^ i) % 10;
        }
        return c;
    }
    
    int d2(int n) {
        int c = n;
        for (int i = 9; i >= 0; --i) {
            c = (c ^ i) % 10;
        }
        return c;
    }
    
    int f(int n) {
        String s = Integer.toString(n);
        String ret = "";
        for (int i = 0; i < s.length(); ++i) {
            int c = s.charAt(i) - '0';
            if (i != 0) {
                for (int j = 9; j >= 1; --j) {
                    c = (c ^ j) % 10;
                    c = (c ^ j) % 10;
                }
                ret += (char)('0' + c);
            }
            else {
                for (int j = c - 1; j >= 1; --j) {
                    c = (c ^ j) % 10;
                    c = (c ^ j) % 10;
                }
                ret += (char)('0' + c);
            }
        }
        return Integer.parseInt(ret);
    }
}