import java.util.*;

public class PerfectPermutation {
    public int reorder(int[] P) {
        int numGroup = 0;
        int n = P.length;
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++numGroup;
                int j = i;
                do {
                    visited[j] = true;
                    j = P[j];
                } while (!visited[j]);
            }
        }
        if (numGroup == 1) return 0;
        else return numGroup;
    }
}