class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> has;
        vector<int> indices;
        for (int i = 0; i < numbers.size(); ++i) {
            int rest = target - numbers[i];
            if (has.find(rest) != has.end()) {
                indices.push_back(has[rest] + 1);
                indices.push_back(i + 1);
                return indices;
            } else {
                has[numbers[i]] = i;
            }
        }
    }
};
