import java.util.*;

public class Solution {
    static int[][] d = new int[501][501];
    public int minDistance(String word1, String word2) {
        if (word1.length() == 0) return word2.length();
        if (word2.length() == 0) return word1.length();

        for (int i = 0; i <= word1.length(); ++i)
            for (int j = 0; j <= word2.length(); ++j)
                d[i][j] = Integer.MAX_VALUE;
        d[0][0] = 0;

        for (int i = 0; i <= word1.length(); ++i)
            for (int j = 0; j <= word2.length(); ++j) {
                if (i < word1.length() && j < word2.length()) {
                    if (word1.charAt(i) == word2.charAt(j)) {
                        if (d[i + 1][j + 1] > d[i][j]) d[i + 1][j + 1] = d[i][j];
                    } else {
                        if (d[i + 1][j + 1] > d[i][j] + 1) d[i + 1][j + 1] = d[i][j] + 1;
                    }
                }
                if (i < word1.length() && d[i + 1][j] > d[i][j] + 1) {
                    d[i + 1][j] = d[i][j] + 1;
                }
                if (j < word2.length() && d[i][j + 1] > d[i][j] + 1) {
                    d[i][j + 1] = d[i][j] + 1;
                }
            }

        return d[word1.length()][word2.length()];
    }
}
