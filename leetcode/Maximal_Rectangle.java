import java.util.*;

public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int nrow = matrix.length;
        if (nrow == 0) return 0;
        int ncol = matrix[0].length;
        int[][] h = new int[nrow][ncol];
        for (int i = nrow - 1; i >= 0; --i)
            for (int j = 0; j < ncol; ++j) {
                if (matrix[i][j] == '0') {
                    h[i][j] = 0;
                } else {
                    if (i == nrow - 1 || matrix[i + 1][j] == '0') h[i][j] = 1;
                    else h[i][j] = h[i + 1][j] + 1;
                }
            }

        int ret = 0;
        int[] e = new int[nrow + 1];
        for (int i = 0; i < nrow; ++i) {
            int c = 0;
            e[0] = -1;
            for (int j = 1; j <= nrow - i; ++j) e[j] = -100;
            for (int j = 0; j < ncol; ++j) {
                while (c < h[i][j]) {
                    if (e[c] != - 100) {
                        int area = c * (j - e[c] + 1);
                        if (area > ret) ret = area;
                    }
                    ++c;
                    e[c] = j;
                }
                while (c > h[i][j]) {
                    e[c] = -100;
                    --c;
                    int area = c * (j - e[c]);
                    if (area > ret) ret = area;
                }
                int area = c * (j - e[c] + 1);
                if (area > ret) ret = area;
            }
            while (c > 0) {
                --c;
                int area = c * (ncol - e[c]);
                if (area > ret) ret = area;
            }

            c = 0;
            e[0] = ncol;
            for (int j = 1; j <= nrow - i; ++j) e[j] = -100;
            for (int j = ncol - 1; j >= 0; --j) {
                while (c < h[i][j]) {
                    if (e[c] != -100) {
                        int area = c * (e[c] - j + 1);
                        if (area > ret) ret = area;
                    }
                    ++c;
                    e[c] = j;
                }
                while (c > h[i][j]) {
                    e[c] = -100;
                    --c;
                    int area = c * (e[c] - j);
                    if (area > ret) ret = area;
                }
                int area = c * (e[c] - j + 1);
                if (area > ret) ret = area;
            }
            while (c > 0) {
                --c;
                int area = c * (e[c] + 1);
                if (area > ret) ret = area;
            }
        }
        return ret;
    }
}