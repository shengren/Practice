import java.util.*;

public class SilverDistance {
    public int minSteps(int sx, int sy, int gx, int gy) {
        gx -= sx;
        gy -= sy;
        int ret = 0;
        if (Math.abs(gx + gy) % 2 != 0) {
            ret = 1;
            gy -= 1;
        }
        ret += Math.max(Math.abs(gx), Math.abs(gy));
        return ret;
    }
}