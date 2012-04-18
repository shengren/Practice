import java.util.*;

public class DucksAlignment {
    public int minimumTime(String[] grid) {
        int nRow = grid.length;
        int nCol = grid[0].length();
        int nDuck = 0;
        int[] markRow = new int[nCol];
        int[] markCol = new int[nRow];
        for (int i = 0; i < nRow; ++i) markCol[i] = -1;
        for (int j = 0; j < nCol; ++j) markRow[j] = -1;
        
        for (int i = 0; i < nRow; ++i)
            for (int j = 0; j < nCol; ++j)
                if (grid[i].charAt(j) == 'o') {
                    ++nDuck;
                    markRow[j] = i;
                    markCol[i] = j;
                }

        int a = 987654321;
        for (int i = 0; i < nRow; ++i) {
            int na = 0;
            for (int j = 0; j < nCol; ++j)
                if (markRow[j] != -1)
                    na += Math.abs(i - markRow[j]);
            if (na < a) a = na;
        }
        System.out.println(a);
        int b = 987654321;
        for (int j = 0; j <= nCol - nDuck; ++j) {
            int p = j;
            int nb = 0;
            for (int k = 0; k < nCol; ++k)
                if (markRow[k] != -1) {
                    nb += Math.abs(p - k);
                    ++p;
                }
            if (nb < b) b = nb;
        }
        System.out.println(b);
        
        int c = 987654321;
        for (int j = 0; j < nCol; ++j) {
            int nc = 0;
            for (int i = 0; i < nRow; ++i)
                if (markCol[i] != -1)
                    nc += Math.abs(j - markCol[i]);
            if (nc < c) c = nc;
        }
        System.out.println(c);
        int d = 987654321;
        for (int i = 0; i <= nRow - nDuck; ++i) {
            int p = i;
            int nd = 0;
            for (int k = 0; k < nRow; ++k)
                if (markCol[k] != -1) {
                    nd += Math.abs(p - k);
                    ++p;
                }
            if (nd < d) d = nd;
        }
        System.out.println(d);
        
        if (a + b < c + d) return a + b;
        return c + d;
    }
}