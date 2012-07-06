/*
LSR 11-09-05

Got the idea, but made wrong answers many times. Used test cases to debug.
*/

import java.util.*;

public class MagicalSource {
    public long calculate(long x) {
        String sx = Long.toString(x);
        String sres = sx;

        for (int i = 1; i < sx.length(); ++i) {  // enumerate the length of the answer
            String s = "";
            int sum = 0;
            int inc = 0;
            int num = 0;
            int totalNumOfAdd = sx.length() + 1 - i;  // the maximum number of possible additions; used to remove tailing digits (maintaining 'sum')
            for (int j = i - 1; j >= 0; --j) {
                int b = sx.charAt(sx.length() - i + j) - '0';
                int a = (b + 10 - (sum + inc) % 10) % 10;
                s = Integer.toString(a) + s;
                sum += a;
                inc = (sum + inc) / 10;  // do not forget plus 'inc'
                if (++num > totalNumOfAdd - 1) {  // maintaining 'sum', not all the tailing digits will participate the additions in the following steps
                    sum -= s.charAt(totalNumOfAdd - 1) - '0';
                    --num;
                }
            }
            if (check(Long.parseLong(s), x)) {
                if (s.compareTo(sres) < 0) sres = s;
            }
        }

        return Long.parseLong(sres);
    }

    boolean check(long n, long x) {
    	if (n == 0) return false;  // bug fixed point
        long t = n;
        while (t < x) {
        	n *= 10;
        	t += n;
        }
        return t == x;
    }
}