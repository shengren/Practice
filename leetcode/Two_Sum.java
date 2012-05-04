import java.util.*;

public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < numbers.length; ++i)
            map.put(numbers[i], i + 1);
        int[] ret = new int[2];
        for (int i = 0; i < numbers.length; ++i) {
            int x = target - numbers[i];
            if (map.containsKey(x)) {
                ret[0] = i + 1;
                ret[1] = map.get(x);
                break;
            }
        }
        return ret;
    }
}
