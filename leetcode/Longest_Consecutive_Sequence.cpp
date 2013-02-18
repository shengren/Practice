typedef pair<int, int> Range;

class Solution {
    unordered_map<int, Range> ht;
    int max_length;
public:
    int longestConsecutive(vector<int> &num) {
        ht.clear();
        max_length = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (ht.find(num[i]) != ht.end())  // Duplicate
                continue;
            if (ht.find(num[i] - 1) != ht.end() &&
                ht.find(num[i] + 1) != ht.end()) {
                Range *left  = &ht[num[i] - 1];
                Range *right = &ht[num[i] + 1];
                int start = num[i] - 1;
                while (start != left->first) {
                    start = left->first;
                    left = &ht[start];
                }
                left->second = right->second;
                ht[num[i] + 1] = ht[num[i]] = *left;
            } else if (ht.find(num[i] - 1) != ht.end()) {
                Range *left = &ht[num[i] - 1];
                int start = num[i] - 1;
                while (start != left->first) {
                    start = left->first;
                    left = &ht[start];
                }
                left->second = num[i];
                ht[num[i]] = *left;
            } else if (ht.find(num[i] + 1) != ht.end()) {
                Range *right = &ht[num[i] + 1];
                right->first = num[i];
                ht[num[i]] = *right;
            } else {
                ht[num[i]] = make_pair(num[i], num[i]);
            }
            const Range &current = ht[num[i]];
            if (max_length < current.second - current.first + 1)
                max_length = current.second - current.first + 1;
        }
        return max_length;
    }
};
