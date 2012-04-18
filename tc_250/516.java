import java.util.*;

public class NetworkXOneTimePad {
    public int crack(String[] plaintexts, String[] cipertexts) {
        long[] plain = new long[plaintexts.length];
        long[] ciper = new long[cipertexts.length];
        for (int i = 0; i < plain.length; ++i) {
            plain[i] = Long.parseLong(plaintexts[i], 2);
        }
        for (int i = 0; i < ciper.length; ++i) {
            ciper[i] = Long.parseLong(cipertexts[i], 2);
        }
        int ret = 0;
        for (int i = 0; i < plain.length; ++i) {
            long key = plain[i] ^ ciper[0];
            boolean flag = true;
            for (int j = 1; j < ciper.length; ++j) {
                long test = key ^ ciper[j];
                flag = false;
                for (int k = 0; k < plain.length; ++k)
                    if (plain[k] == test) {
                        flag = true;
                        break;
                    }
                if (!flag)
                    break;
            }
            if (flag)
                ++ret;
        }
        return ret;
    }
}