typedef pair<int, int> PII;

class Solution {
    unordered_map<int, int> counter;
    unordered_map<int, vector<PII> > dictionary;
    vector<vector<int> > quadruplets;
    bool validate(vector<int> &quad) {
        for (int i = 0; i < 4;) {
            int j = i + 1;
            int c = 1;
            while (j < 4 && quad[j] == quad[i]) {
                ++j;
                ++c;
            }
            if (c > counter[quad[i]])
                return false;
            i = j;
        }
        return true;
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        counter.clear();
        for (int i = 0; i < num.size(); ++i)
            if (counter.find(num[i]) == counter.end())
                counter[num[i]] = 1;
            else
                counter[num[i]]++;
        dictionary.clear();
        for (int i = 0; i < num.size(); ++i) {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            for (int j = i + 1; j < num.size(); ++j) {
                // Forgot 'j > i + 1' at first
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;
                int key = num[i] + num[j];
                if (dictionary.find(key) == dictionary.end()) {
                    vector<PII> vpii;
                    dictionary[key] = vpii;
                }
                dictionary[key].push_back(make_pair(num[i], num[j]));
            }
        }
        quadruplets.clear();
        vector<int> quad;
        for (int i = 0; i < num.size(); ++i) {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            for (int j = i + 1; j < num.size(); ++j) {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;
                int key = target - num[i] - num[j];
                if (dictionary.find(key) == dictionary.end())
                    continue;
                const vector<PII> &vpii = dictionary[key];
                for (int k = 0; k < vpii.size(); ++k) {  // Third level loop
                    const PII &pii = vpii[k];
                    if (num[j] > pii.first)
                        continue;
                    quad.clear();
                    quad.push_back(num[i]);
                    quad.push_back(num[j]);
                    quad.push_back(pii.first);
                    quad.push_back(pii.second);
                    if (validate(quad))
                        quadruplets.push_back(quad);
                }
            }
        }
        return quadruplets;
    }
};
