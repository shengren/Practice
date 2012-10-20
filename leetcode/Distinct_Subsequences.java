import java.util.*;

public class Solution {
    public int numDistinct(String S, String T) {
        int[][] d = new int[S.length() + 1][T.length() + 1];
        for (int i = 0; i <= S.length(); ++i)
            for (int j = 0; j <= T.length(); ++j)
                d[i][j] = 0;
        d[0][0] = 1;

        for (int i = 0; i < S.length(); ++i)
            for (int j = 0; j <= T.length(); ++j)
                if (d[i][j] != 0) {
                    d[i + 1][j] += d[i][j];
                    if (j < T.length() && S.charAt(i) == T.charAt(j))
                        d[i + 1][j + 1] += d[i][j];
                }

        return d[S.length()][T.length()];
    }
}
