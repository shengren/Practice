class Solution {
    vector<vector<int> > combinations;
    void generate(int k, vector<int> &candidates, int sum, 
                  vector<int> &combination, int target) {
        if (sum == target) {
            combinations.push_back(combination);
            return;
        }
        if (k == candidates.size())
            return;
        if (sum + candidates[k] > target)
            return;
        // Use k-th element
        combination.push_back(candidates[k]);
        generate(k + 1, candidates, sum + candidates[k], combination, target);
        combination.pop_back();
        // Not use k-th element
        int next_k = k + 1;  // In order to avoid duplicate combination
        while (next_k < candidates.size() && 
               candidates[next_k] == candidates[k])
            ++next_k;
        generate(next_k, candidates, sum, combination, target);
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        combinations.clear();
        sort(num.begin(), num.end());
        vector<int> combination;
        generate(0, num, 0, combination, target);
        return combinations;
    }
};
