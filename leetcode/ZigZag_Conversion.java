import java.util.*;

public class Solution {
    public String convert(String s, int nRows) {
        if (nRows == 1) return s;
        int len = s.length();
        int nCols = len / (nRows + nRows - 2) * (nRows - 1);
        int n = len / (nRows + nRows - 2) * (nRows + nRows - 2);
        if (n < len) {
            nCols += 1;
            n += nRows;
        }
        if (n < len) {
            nCols += len - n;
        }
        char[][] pad = new char[nRows][nCols];
        for (int i = 0; i < nRows; ++i)
            for (int j = 0; j < nCols; ++j)
                pad[i][j] = ' ';
        for (int i = 0; i < len; ++i) {
            int co = i / (nRows + nRows - 2) * (nRows - 1);
            int x = i % (nRows + nRows - 2);
            if (x < nRows) {
                pad[x][co] = s.charAt(i);
            } else {
                x -= nRows;
                pad[nRows - 2 - x][co + 1 + x] = s.charAt(i);
            }
        }
        String ret = "";
        for (int i = 0; i < nRows; ++i)
            for (int j = 0; j < nCols; ++j)
                if (pad[i][j] != ' ') {
                    ret += pad[i][j];
                }
        return ret;
    }
}
