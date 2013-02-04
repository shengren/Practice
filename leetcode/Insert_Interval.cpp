/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> after_insertion;
        bool has_inserted = false;  // Need this flag
        for (int i = 0; i < intervals.size(); ++i)
            if (intervals[i].end < newInterval.start) {
                after_insertion.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                if (!has_inserted) {
                    has_inserted = true;
                    after_insertion.push_back(newInterval);
                }
                after_insertion.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end   = max(newInterval.end,   intervals[i].end);
            }
        if (!has_inserted)
            after_insertion.push_back(newInterval);
        return after_insertion;
    }
};
