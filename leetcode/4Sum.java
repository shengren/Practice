import java.util.*;

class Pair {
    int x;
    int y;
    Pair(int _x, int _y) {  // _x <= _y
        x = _x;
        y = _y;
    }
}

public class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
        Arrays.sort(num);
        HashMap<Integer, Integer> count = new HashMap<Integer, Integer>();
        for (int i = 0; i < num.length; ++i) {
            if (count.containsKey(num[i])) {
                count.put(num[i], count.get(num[i]) + 1);
            } else {
                count.put(num[i], 1);
            }
        }
        HashMap<Integer, ArrayList<Pair>> table = new HashMap<Integer, ArrayList<Pair>>();
        for (int i = 0; i < num.length; ++i)
            for (int j = i + 1; j < num.length; ++j) {
                int key = num[i] + num[j];
                Pair p = new Pair(num[i], num[j]);
                if (table.containsKey(key)) {
                    ArrayList<Pair> ls = table.get(key);
                    ListIterator<Pair> it = ls.listIterator();
                    boolean flag = true;
                    while (it.hasNext()) {
                        Pair q = it.next();
                        if (p.x == q.x && p.y == q.y) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ls.add(p);
                        table.put(key, ls);
                    }
                } else {
                    ArrayList<Pair> ls = new ArrayList<Pair>();
                    ls.add(p);
                    table.put(key, ls);
                }
            }
        HashSet<ArrayList<Integer>> ans = new HashSet<ArrayList<Integer>>();
        for (int i = 0; i < num.length; ++i)
            for (int j = i + 1; j < num.length; ++j) {  // num[i] <= num[j]
                int key = target - num[i] - num[j];
                if (table.containsKey(key)) {
                    ArrayList<Pair> ls = table.get(key);
                    ListIterator<Pair> it = ls.listIterator();
                    while (it.hasNext()) {
                        Pair p = it.next();
                        if (num[j] <= p.x) {
                            int ct = (num[i] == num[j]) ? 2 : 1;
                            if (num[j] == p.x) ++ct;
                            if (num[j] == p.y) ++ct;
                            if (count.get(num[j]) >= ct) {
                                ArrayList<Integer> res = new ArrayList<Integer>();
                                res.add(num[i]);
                                res.add(num[j]);
                                res.add(p.x);
                                res.add(p.y);
                                ans.add(res);
                            }
                        }
                    }
                }
            }
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        Iterator<ArrayList<Integer>> it = ans.iterator();
        while (it.hasNext()) {
            ret.add(it.next());
        }
        return ret;
    }
}
