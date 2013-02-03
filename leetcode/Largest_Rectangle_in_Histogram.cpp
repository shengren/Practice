class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        // Both sides can be extended. Precomputing speeds up the expansion.
        vector<int> leftmost(n);
        vector<int> rightmost(n);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && height[i] <= height[i - 1])
                leftmost[i] = leftmost[i - 1];
            else
                leftmost[i] = i;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && height[i] <= height[i + 1])
                rightmost[i] = rightmost[i + 1];
            else
                rightmost[i] = i;
        }
        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            int left_bound = leftmost[i];
            while (left_bound > 0 && height[i] <= height[left_bound - 1])
                left_bound = leftmost[left_bound - 1];
            int right_bound = rightmost[i];
            while (right_bound < n -1 && height[i] <= height[right_bound + 1])
                right_bound = rightmost[right_bound + 1];
            if (max_area < height[i] * (right_bound - left_bound + 1))
                max_area = height[i] * (right_bound - left_bound + 1);
        }
        return max_area;
    }
};
