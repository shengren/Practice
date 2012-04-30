import java.util.*;

public class Solution {
    public int removeDuplicates(int[] A) {
        if (A.length == 0) return 0;
        int cur = 0;
        for (int i = 1; i < A.length; ++i) {
            if (A[cur] != A[i]) {
                ++cur;
                A[cur] = A[i];
            }
        }
        return cur + 1;
    }
}