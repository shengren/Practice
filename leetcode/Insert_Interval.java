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

public class Solution {
    boolean intersect(Interval a, Interval b) {
        if (b.start >= a.start && b.start <= a.end) return true;
        if (b.end >= a.start && b.end <= a.end) return true;
        if (a.start >= b.start && a.start <= b.end) return true;
        return false;
    }
    void merge(Interval a, Interval b) {
        b.start = Math.min(a.start, b.start);
        b.end = Math.max(a.end, b.end);
    }
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        ArrayList<Interval> ret = new ArrayList<Interval>();
        Object[] inter = intervals.toArray();
        int i = 0;
        while (i < inter.length && ((Interval)inter[i]).end < newInterval.start) {
            ret.add((Interval)inter[i]);
            ++i;
        }
        while (i < inter.length && intersect((Interval)inter[i], newInterval)) {
            merge((Interval)inter[i], newInterval);
            ++i;
        }
        ret.add(newInterval);
        while (i < inter.length && ((Interval)inter[i]).start > newInterval.end) {
            ret.add((Interval)inter[i]);
            ++i;
        }
        return ret;
    }
}
