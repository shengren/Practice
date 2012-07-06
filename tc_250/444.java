import java.util.*;

public class UnfoldingTriangles {
    String[] grid;
    int numRow, numCol;

    public int solve(String[] grid, int unfoldLimit) {
        this.grid = grid;
        numRow = grid.length;
        numCol = grid[0].length();
        int maxSideLength = Math.min(numRow, numCol);
        for (int s = maxSideLength; s >= 1; --s)
            for (int i = 0; i + s <= numRow; ++i)
                for (int j = 0; j + s <= numCol; ++j) {
                    if (!isValid(i, j, s)) continue;
                    int numFold = getNumFold(i, j, s);
                    if (numFold == -1) continue;
                    if (numFold <= unfoldLimit) return (1 + s) * s / 2;
                }
        return -1;
    }

    boolean isValid(int x, int y, int s) {
        for (int i = 0; i < s; ++i)
            if (grid[x + i].charAt(y + s - 1 - i) != '/')
                return false;
        if (y + s < numCol) {
            for (int i = 0; i < s; ++i)
                if (grid[x + i].charAt(y + s) == '#')
                    return false;
        }
        if (x + s < numRow) {
            for (int i = 0; i < s; ++i)
                if (grid[x + s].charAt(y + i) == '#')
                    return false;
        }
        return true;
    }

    int getNumFold(int x, int y, int s) {
        int ret = 0;
        for (int i = 1; i < s; ++i)
            for (int j = s - 1; j > s - 1 - i; --j) {
                if (grid[x + i].charAt(y + j) == '.') {
                    return -1;
                } else if (grid[x + i].charAt(y + j) == '/') {
                    ++ret;
                }
            }
        return ret;
    }
}