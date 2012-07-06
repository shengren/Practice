import java.util.*;

public class ToastXToast {
    public int bake(int[] undertoasted, int[] overtoasted) {
        Arrays.sort(undertoasted);
        Arrays.sort(overtoasted);
        if (undertoasted.length == 1) {
            return (undertoasted[0] < overtoasted[0]) ? 1 : -1;
        }
        if (overtoasted.length == 1) {
            return (overtoasted[0] > 
                    undertoasted[undertoasted.length - 1]) ? 1 : -1;
        }
        if (undertoasted[undertoasted.length - 1] < overtoasted[0])
            return 1;
        if (undertoasted[0] < overtoasted[0] && 
            undertoasted[undertoasted.length - 1] < 
                overtoasted[overtoasted.length - 1])
            return 2;
        return -1;
    }
}