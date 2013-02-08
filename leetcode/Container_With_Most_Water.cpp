class Solution {
    int binarySearch(vector<int> &h,
                     vector<int> &c,
                     int beg,
                     int end,
                     int target) {
        if (beg + 1 == end) {
            if (h[c[beg]] >= target)
                return beg - 1;
            else
                return beg;
        }
        int mid = (beg + end) / 2;
        if (h[c[mid]] >= target)
            return binarySearch(h, c, beg, mid, target);
        else
            return binarySearch(h, c, mid, end, target);
    }
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        if (n == 0)
            return 0;
        // from_left[i] is the smallest index that satisfies
        // from_left[i] > from_left[i - 1] and
        // height[from_left[i]] > height[from_left[i - 1]].
        vector<int> from_left;
        from_left.push_back(0);
        for (int i = 1; i < n; ++i)
            if (height[i] > height[from_left[from_left.size() - 1]])
                from_left.push_back(i);
        // from_right[i] is the largest index that satisfies
        // from_right[i] < from_right[i - 1] and
        // height[from_right[i]] > height[from_right[i - 1]].
        vector<int> from_right;
        from_right.push_back(n - 1);
        for (int i = n - 2; i >= 0; --i)
            if (height[i] > height[from_right[from_right.size() - 1]])
                from_right.push_back(i);

        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && 
                height[i] <= height[from_left[from_left.size() - 1]]) {
                int leftmost = from_left[1 + binarySearch(height, 
                                                          from_left, 
                                                          0, 
                                                          from_left.size(), 
                                                          height[i])];
                if (max_area < height[i] * (i - leftmost))
                    max_area = height[i] * (i - leftmost);
            }
            if (i < n - 1 && 
                height[i] <= height[from_right[from_right.size() - 1]]) {
                int rightmost = from_right[1 + binarySearch(height, 
                                                            from_right, 
                                                            0, 
                                                            from_right.size(), 
                                                            height[i])];
                if (max_area < height[i] * (rightmost - i))
                    max_area = height[i] * (rightmost - i);
            }
        }
        return max_area;
    }
};
