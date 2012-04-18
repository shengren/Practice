import java.util.*;

public class Solution {
    public int firstMissingPositive(int[] A) {
        boolean[] has = new boolean[A.length + 2];
        int miss = 1;
        for (int i = 0; i < A.length; ++i) 
            if (A[i] >= 1 && A[i] <= A.length) {
                has[A[i]] = true;
                while (has[miss]) {
                    ++miss;
                }
            }
        return miss;
    }
}
