import java.util.*;

public class OrderedNim {
    public String winner(int[] layout) {
        boolean preWinnable = true;
        for (int i = layout.length - 2; i >= 0; --i) {
            if (preWinnable) {
                preWinnable = (layout[i] > 1) ? true : false;
            }
            else {
                preWinnable = true;
            }
        }
        return preWinnable ? "Alice" : "Bob";
    }
}