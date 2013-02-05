class Solution {
    vector<vector<int> > combinations;
    void generate(int k, vector<int> &candidates, int sum, 
                  vector<int> &combination, int target) {
        if (k == candidates.size()) {
            if (sum == target)
                combinations.push_back(combination);
            return;
        }
        for (int i = 0; sum + candidates[k] * i <= target; ++i) {
            for (int j = 1; j <= i; ++j)
                combination.push_back(candidates[k]);
            generate(k + 1, candidates, sum + candidates[k] * i, 
                     combination, target);
            for (int j = 1; j <= i; ++j)
                combination.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        combinations.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        generate(0, candidates, 0, combination, target);
        return combinations;
    }
};
