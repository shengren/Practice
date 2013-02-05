class Solution {
    vector<vector<int> > permutations;
    void generate(int k, int n, vector<int> &num, vector<bool> &has, 
                  vector<int> &scratch_pad) {
        if (k > n) {
            permutations.push_back(scratch_pad);
            return;
        }
        int passed = num[0] - 1;  // Magic number
        for (int i = 0; i < n; ++i)
            if (has[i] && num[i] != passed) {
                scratch_pad.push_back(num[i]);
                has[i] = false;
                generate(k + 1, n, num, has, scratch_pad);
                scratch_pad.pop_back();
                has[i] = true;
                passed = num[i];
            }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        permutations.clear();
        sort(num.begin(), num.end());
        int n = num.size();
        vector<bool> has(n, true);
        vector<int> scratch_pad;
        generate(1, n, num, has, scratch_pad);
        return permutations;
    }
};
