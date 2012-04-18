import java.util.*;

public class Solution {
    public static ArrayList<Integer> cloneList(ArrayList<Integer> list) {
        ArrayList<Integer> clone = new ArrayList<Integer>(list.size());
        for (Integer item: list) clone.add(item);
        return clone;
    }
    public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
        Arrays.sort(num);
        HashMap<Integer, Integer> single = new HashMap<Integer, Integer>();
        for (int i = 0; i < num.length; ++i) {
            if (single.containsKey(num[i])) {
                int old = single.get(num[i]);
                single.put(num[i], old + 1);
            } else {
                single.put(num[i], 1);
            }
        }
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        HashSet<ArrayList<Integer>> pair = new HashSet<ArrayList<Integer>>();
        for (int i = 0; i < num.length; ++i)
            for (int j = i + 1; j < num.length; ++j) {
                ArrayList<Integer> x = new ArrayList<Integer>();
                x.add(num[i]);
                x.add(num[j]);
                if (!pair.contains(x)) {
                    int y = 0 - num[i] - num[j];
                    if (y < num[j]) continue;
                    int ct = 1;
                    if (y == num[i]) ct++;
                    if (y == num[j]) ct++;
                    pair.add(cloneList(x));
                    if (single.containsKey(y)) {
                        int z = single.get(y);
                        if (z >= ct) {
                            x.add(y);
                            ret.add(cloneList(x));
                        }
                    }
                    
                }
            }
        return ret;
    }
}
