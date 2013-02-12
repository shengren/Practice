typedef pair<int, int> PII;
typedef pair<char, int> PCI;

class Solution {
public:
    string minWindow(string S, string T) {
        map<char, PII> dictionary;
        queue<PCI> buffer;
        set<char> missed;
        string min_window = "";
        for (int i = 0; i < T.length(); ++i)
            if (dictionary.find(T[i]) != dictionary.end()) {
                dictionary[T[i]].first++;
            } else {
                dictionary[T[i]].first = 1;
                dictionary[T[i]].second = 0;
                missed.insert(T[i]);
            }
        for (int i = 0; i < S.length(); ++i)
            if (dictionary.find(S[i]) != dictionary.end()) {
                buffer.push(make_pair(S[i], i));
                dictionary[S[i]].second++;
                if (dictionary[S[i]].second >= dictionary[S[i]].first)
                    missed.erase(S[i]);
                if (missed.empty()) {
                    while (true) {
                        PCI pci = buffer.front();
                        if (dictionary[pci.first].first == 
                            dictionary[pci.first].second)
                            break;
                        buffer.pop();
                        dictionary[pci.first].second--;
                    }
                    string window = 
                        S.substr(
                            buffer.front().second,
                            buffer.back().second - buffer.front().second + 1
                            );
                    if (min_window == "" || 
                        min_window.length() > window.length())
                        min_window = window;
                }
            }
        return min_window;
    }
};
