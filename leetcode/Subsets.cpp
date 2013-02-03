class Solution {
    vector<vector<int> > sets;
    void findSubset(vector<int> &S, int idx, vector<int> &current) {
        if (idx == S.size()) {
            sets.push_back(current);
            return;
        }
        findSubset(S, idx + 1, current);
        current.push_back(S[idx]);
        findSubset(S, idx + 1, current);
        current.pop_back();
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        sets.clear();
        vector<int> s;
        findSubset(S, 0, s);
        return sets;
    }
};
