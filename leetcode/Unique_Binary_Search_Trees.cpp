class Solution {
public:
    int numTrees(int n) {
        vector<int> cache;
        cache.push_back(1);  // n == 0
        cache.push_back(1);  // n == 1
        for (int i = 2; i <= n; ++i) {
            int sum = 0;
            for (int j = 0; j < i; ++j)
                sum += cache[j] * cache[i - 1 - j];
            cache.push_back(sum);
        }
        return cache[n];
    }
};
