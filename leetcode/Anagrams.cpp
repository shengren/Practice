class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > dict;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());  // key
            if (dict.find(s) == dict.end())
                dict[s] = vector<string>();
            dict[s].push_back(strs[i]);
        }
        vector<string> anagrams;  // all the groups are stored together
        for (map<string, vector<string> >::iterator it = dict.begin();
             it != dict.end();
             ++it) {
            vector<string> &words = it->second;
            if (words.size() > 1)
                for (int i = 0; i < words.size(); ++i)
                    anagrams.push_back(words[i]);
        }
        return anagrams;
    }
};
