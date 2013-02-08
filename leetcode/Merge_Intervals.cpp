/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compareIntervals(const Interval &a, const Interval &b) {
    if (a.start == b.start)
        return a.end > b.end;
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compareIntervals);
        vector<Interval> after_mergence;
        after_mergence.push_back(intervals[0]);
        for (int i = 1; i < n; ++i)
            if (intervals[i].start > after_mergence.back().end)
                after_mergence.push_back(intervals[i]);
            else
                after_mergence.back().end = max(after_mergence.back().end, 
                                                intervals[i].end);
        return after_mergence;
    }
};
