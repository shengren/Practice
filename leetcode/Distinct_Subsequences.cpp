class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> num_matched(T.length() + 1);
        num_matched[0] = 1;
        for (int j = 1; j < num_matched.size(); ++j)
            num_matched[j] = 0;
        for (int i = 0; i < S.length(); ++i)
            for (int j = num_matched.size() - 1; j >= 0; --j)
                if (num_matched[j] > 0 && T[j] == S[i])
                    num_matched[j + 1] += num_matched[j];
        return num_matched[T.length()];
    }
};
