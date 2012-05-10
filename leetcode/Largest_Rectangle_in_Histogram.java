import java.util.*;

public class Solution {
    public int largestRectangleArea(int[] height) {
        if (height.length == 0) return 0;
        int[] sorted = new int[height.length];
        System.arraycopy(height, 0, sorted, 0, height.length);
        Arrays.sort(sorted);
        int maxh = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < sorted.length; ++i)
            if (i == 0 || sorted[i] > sorted[i - 1]) {
                map.put(sorted[i], maxh);
                ++maxh;
            }
        int[] ivmap = new int[maxh];
        int k = 0;
        for (int i = 0; i < sorted.length; ++i)
            if (i == 0 || sorted[i] > sorted[i - 1]) {
                ivmap[k] = sorted[i];
                ++k;
            }

        int ret = 0;
        int[] farend = new int[maxh];
        for (int i = 0; i < maxh; ++i) farend[i] = -1;
        int curh = -1;
        for (int i = 0; i < height.length; ++i) {
            int h = map.get(height[i]);
            while (curh < h) {
                ++curh;
                farend[curh] = i;
            }
            while (curh > h) {
                int area = ivmap[curh] * (i - farend[curh]);
                if (area > ret) ret = area;
                farend[curh] = -1;
                --curh;
            }
            int area = height[i] * (i - farend[h] + 1);
            if (area > ret) ret = area;
        }
        while (curh >= 0) {
            int area = ivmap[curh] * (height.length - farend[curh]);
            if (area > ret) ret = area;
            --curh;
        }

        return ret;
    }
}