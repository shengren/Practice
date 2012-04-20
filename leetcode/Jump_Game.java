import java.util.*;

public class Solution {
    public boolean canJump(int[] A) {
        int p = 0;
        for (int i = 0; i < A.length; ++i)
            if (i <= p) {
                p = Math.max(p, i + A[i]);
                if (p >= A.length - 1) return true;
            }
        return false;
    }
}