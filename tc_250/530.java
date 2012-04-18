import java.util.*;

public class GogoXCake {
    boolean okay(int r, int c, char[][] cake, char[][] cutter, char[][] new_cake) {
        int cutter_r = cutter.length;
        int cutter_c = cutter[0].length;
        for (int i = 0; i < cutter_r; ++i)
            for (int j = 0; j < cutter_c; ++j) {
                if (cutter[i][j] == '.') {
                     if (cake[r + i][c + j] == '.') {
                         new_cake[r + i][c + j] = 'X';
                     } else {
                         return false;
                     }
                }
            }
        return true;
    }
    boolean test(int r, int c, char[][] cake, char[][] cutter) {
        int cake_r = cake.length;
        int cake_c = cake[0].length;
        int cutter_r = cutter.length;
        int cutter_c = cutter[0].length;
        if (r > cake_r - cutter_r || c > cake_c - cutter_c) {
            for (int i = 0; i < cake_r; ++i)
                for (int j = 0; j < cake_c; ++j)
                    if (cake[i][j] == '.')
                        return false;
            return true;
        }
        if (c == cake_c - cutter_c) {
            boolean res = test(r + 1, 0, cake, cutter);
            if (res) return true;
        } else {
            boolean res = test(r, c + 1, cake, cutter);
            if (res) return true;
        }
        char[][] new_cake = new char[cake_r][cake_c];
        for (int i = 0; i < cake_r; ++i)
            for (int j = 0; j < cake_c; ++j)
                new_cake[i][j] = cake[i][j];
        if (okay(r, c, cake, cutter, new_cake)) {
            if (c == cake_c - cutter_c) {
                boolean res = test(r + 1, 0, new_cake, cutter);
                if (res) return true;
            } else {
                boolean res = test(r, c + 1, new_cake, cutter);
                if (res) return true;
            }
        }
        return false;
    }
    public String solve(String[] _cake, String[] _cutter) {
        int cake_r = _cake.length;
        int cake_c = _cake[0].length();
        int cutter_r = _cutter.length;
        int cutter_c = _cutter[0].length();
        char[][] cake = new char[cake_r][cake_c];
        char[][] cutter = new char[cutter_r][cutter_c];
        for (int i = 0; i < cake_r; ++i) cake[i] = _cake[i].toCharArray();
        for (int i = 0; i < cutter_r; ++i) cutter[i] = _cutter[i].toCharArray();
        return test(0, 0, cake, cutter) ? "YES" : "NO";
    }
}