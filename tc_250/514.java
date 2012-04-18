import java.util.*;

public class MagicalGirlLevelOneDivOne {
    public String isReachable(int[] jumpTypes, int x, int y) {
        x = Math.abs(x);
        y = Math.abs(y);
        for (int i = 0; i < jumpTypes.length; ++i) {
            if (jumpTypes[i] % 2 == 0)
                return "YES";
        }
        if ((x + y) % 2 == 0)
            return "YES";
        else
            return "NO";
    }
}