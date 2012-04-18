import java.util.*;

public class Solution {
    public int maxArea(int[] height) {
        int ret = 0;
        int[] leftmost = new int[10001];
        for (int i = 0; i <= 10000; ++i) leftmost[i] = -1;
        int current_max_height = 0;
        for (int i = 0; i < height.length; ++i) {
            if (height[i] > current_max_height) {
                for (int j = current_max_height + 1; j <= height[i]; ++j)
                    leftmost[j] = i;
                current_max_height = height[i];
            }
            if (leftmost[height[i]] != -1) {
                int area = (i - leftmost[height[i]]) * height[i];
                if (area > ret) ret = area;
            }
        }
        int[] rightmost = new int[10001];
        for (int i = 0; i <= 10000; ++i) rightmost[i] = -1;
        current_max_height = 0;
        for (int i = height.length - 1; i >= 0; --i) {
            if (height[i] > current_max_height) {
                for (int j = current_max_height + 1; j <= height[i]; ++j)
                    rightmost[j] = i;
                current_max_height = height[i];
            }
            if (rightmost[height[i]] != -1) {
                int area = (rightmost[height[i]] - i) * height[i];
                if (area > ret) ret = area;
            }
        }

        return ret;
    }
}