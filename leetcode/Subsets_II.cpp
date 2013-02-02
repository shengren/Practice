class Solution {
    vector<vector<int> > subsets;
    void findSubsets(int start, vector<int> &S, vector<int> current) {
        if (start == S.size()) {
            subsets.push_back(current);
            return;
        }
        int element = S[start];
        int count = 1;
        int next_start = start + 1;
        while (next_start < S.size() && S[next_start] == element) {
            ++count;
            ++next_start;
        }
        // Remember selecting zero is an option.
        for (int i = 0; i <= count; ++i) {
            vector<int> next = current;
            for (int j = 1; j <= i; ++j)
                next.push_back(element);
            findSubsets(next_start, S, next);
        }
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        subsets.clear();
        sort(S.begin(), S.end());
        findSubsets(0, S, vector<int>());
        return subsets;
    }
};
