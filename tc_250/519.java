import java.util.*;

public class BinaryCards {
    public long largestNumber(long A, long B) {
        if (A == B) return A;
        int i = 63;
        while (i >= 0) {
            if ((A & (1L << i)) == 0 && (B & (1L << i)) != 0) break;
            --i;
        }
        return B | ((1L << i) - 1);
    }
}