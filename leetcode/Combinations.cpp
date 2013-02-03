class Solution {
    vector<vector<int> > combinations;
    void enumerate(int n, int k, int x, vector<int> &current) {
        if (current.size() == k) {
            combinations.push_back(current);
            return;
        }
        if (x > n)
            return;
        // Do not include x
        enumerate(n, k, x + 1, current);
        // Include x
        current.push_back(x);
        enumerate(n, k, x + 1, current);
        current.pop_back();
    }
public:
    vector<vector<int> > combine(int n, int k) {
        combinations.clear();
        vector<int> current;
        enumerate(n, k, 1, current);
        return combinations;
    }
};
