#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > dict;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (dict.find(s) == dict.end()) {
                vector<string> t;
                dict[s] = t;
            }
            dict[s].push_back(strs[i]);
        }
        vector<string> ret;
        for (map<string, vector<string> >::iterator it = dict.begin();
             it != dict.end(); ++it) {
            if ((it->second).size() > 1) {
                for (int i = 0; i < (it->second).size(); ++i)
                    ret.push_back((it->second)[i]);
            }
        }
        return ret;
    }
};
