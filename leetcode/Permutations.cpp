class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > permutations;
        sort(num.begin(), num.end());
        while (true) {
            permutations.push_back(num);
            if (!next_permutation(num.begin(), num.end()))
                break;
        }
        return permutations;
    }
};
