class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        map<int, int> counter;
        for (int i = 0; i < num.size(); ++i)
            if (i == 0 || num[i] != num[i - 1])
                counter[num[i]] = 1;
            else
                counter[num[i]]++;
        vector<vector<int> > triples;
        for (int i = 0; i < num.size(); ++i)
            if (i == 0 || num[i] != num[i - 1])
                for (int j = i + 1; j < num.size(); ++j)
                    if (j == i + 1 || num[j] != num[j - 1]) {
                        int third = -(num[i] + num[j]);
                        if (third >= num[j] && // Forgot this at first
                            counter.find(third) != counter.end()) {
                            int c = counter[third];
                            if (third == num[i])
                                c--;
                            if (third == num[j])
                                c--;
                            if (c > 0) {
                                vector<int> t;
                                t.push_back(num[i]);
                                t.push_back(num[j]);
                                t.push_back(third);
                                triples.push_back(t);
                            }
                        }
                    }
        return triples;
    }
};
