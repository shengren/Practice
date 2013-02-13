typedef pair<string, int> PSI;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.length() != end.length())
            return 0;
        if (start == "")
            return 0;
        int length = start.length();
        unordered_set<string> reached;
        queue<PSI> checking;
        reached.insert(start);
        checking.push(make_pair(start, 1));
        while (!checking.empty()) {
            PSI psi = checking.front();
            checking.pop();
            for (int i = 0; i < length; ++i)
                for (int j = 0; j < 26; ++j) {
                    string next = psi.first;
                    next[i] = 'a' + j;
                    // Must be different between two consecutive words
                    if (psi.first == next)
                        continue;
                    // 'end' can be not inside 'dict'
                    if (next == end)
                        return psi.second + 1;
                    if (dict.find(next) != dict.end() &&
                        reached.find(next) == reached.end()) {
                        reached.insert(next);
                        checking.push(make_pair(next, psi.second + 1));
                    }
                }
        }
        return 0;
    }
};
