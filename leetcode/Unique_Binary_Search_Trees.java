public class Solution {
    int[] cache = new int[15];
    
    int solve(int n) {
        if (cache[n] != -1)
            return cache[n];
        cache[n] = 0;
        for (int l = 0; l <= n - 1; ++l)
            cache[n] += solve(l) * solve(n - 1 - l);
        return cache[n];
    }
    
    public int numTrees(int n) {
        for (int i = 0; i < 15; ++i)
            cache[i] = -1;
        cache[0] = cache[1] = 1;
        return solve(n);
    }
}

