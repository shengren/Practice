#include <iostrteam>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        do {
            ret.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return ret;
    }
};