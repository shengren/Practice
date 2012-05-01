import java.util.*;

public class Solution {
    public int[] searchRange(int[] A, int target) {
        int a = 0;
        int b = A.length;
        boolean flag = false;
        while (a < b) {
            int m = (a + b) / 2;
            if (A[m] == target) {
                flag = true;
                break;
            } else if (A[m] < target) {
                a = m + 1;
            } else {
                b = m;
            }
        }
        int[] ret = new int[2];
        if (!flag) {
            ret[0] = ret[1] = -1;
            return ret;
        }
        if (A[0] == target) {
            ret[0] = 0;
        } else {
            a = 0;
            b = A.length - 1;
            while (a + 1 < b) {
                int m = (a + b) / 2;
                if (A[m] < target) a = m;
                else b = m;
            }
            ret[0] = b;
        }
        if (A[A.length - 1] == target) {
            ret[1] = A.length - 1;
        } else {
            a = 0;
            b = A.length - 1;
            while (a + 1 < b) {
                int m = (a + b) / 2;
                if (A[m] <= target) a = m;
                else b = m;
            }
            ret[1] = a;
        }
        return ret;
    }
}
