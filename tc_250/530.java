import java.util.*;

public class GogoXCake {
    public String solve(String[] cake, String[] cutter) {
        int cake_r = cake.length;
        int cake_c = cake[0].length();
        int cutter_r = cutter.length;
        int cutter_c = cutter[0].length();
        int offset = 0;
        for (int j = 0; j < cutter_c; ++j)
            if (cutter[0].charAt(j) == '.') {
                offset = j;
                break;
            }
        for (int i = 0; i < cake_r; ++i)
            for (int j = 0; j < cake_c; ++j)
                if (cake[i].charAt(j) == '.') {
                    int x = i;
                    int y = j - offset;
                    if (x < 0 || x > cake_r - cutter_r || y < 0 || y > cake_c - cutter_c)
                        return "NO";
                    for (int a = 0; a < cutter_r; ++a)
                        for (int b = 0; b < cutter_c; ++b)
                            if (cutter[a].charAt(b) == '.') {
                                if (cake[x + a].charAt(y + b) == 'X') return "NO";
                                cake[x + a] = cake[x + a].substring(0, y + b) + "X"
                                            + cake[x + a].substring(y + b + 1);
                            }
                }
         for (int i = 0; i < cake_r; ++i)
            for (int j = 0; j < cake_c; ++j)
                if (cake[i].charAt(j) == '.')
                    return "NO";
         return "YES";
    }
}
