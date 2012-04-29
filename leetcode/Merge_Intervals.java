import java.util.*;

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

/*
class Interval {
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}*/

class IntervalComparator implements Comparator<Interval> {
    public int compare(Interval x1, Interval x2) {
        if (x1.start == x2.start) return x2.end - x1.end;
        return x1.start - x2.start;
    }
}

public class Solution {
    public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
        ArrayList<Interval> ret = new ArrayList<Interval>();
        //if (intervals.size() > 0) return ret;
        Collections.sort(intervals, new IntervalComparator());
        ListIterator<Interval> it = intervals.listIterator();
        Interval cur = null;
        while (it.hasNext()) {
            Interval in = it.next();
            if (cur == null) {
                cur = new Interval(in.start, in.end);
            } else {
                if (in.start <= cur.end) {
                    cur.end = Math.max(cur.end, in.end);
                } else {
                    ret.add(cur);
                    cur = new Interval(in.start, in.end);
                }
            }
        }
        if (cur != null) ret.add(cur);
        return ret;
    }
}