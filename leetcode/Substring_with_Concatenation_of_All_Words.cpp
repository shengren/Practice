typedef pair<int, int> PII;
typedef pair<string, int> PSI;

class Solution {
    vector<int> indices;
    unordered_map<string, PII> records;
    //map<string, PII> records;
    int word_length;
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        indices.clear();
        records.clear();
        word_length = L[0].length();
        // Build hash table
        for (int i = 0; i < L.size(); ++i)
            if (records.find(L[i]) == records.end())
                records[L[i]] = make_pair(1, 0);
            else
                records[L[i]].first++;
        // Enumerate the offset
        for (int start = 0; start < word_length; ++start) {
            queue<PSI> buffer;
            // Reset hash table
            for (unordered_map<string, PII>::iterator iter = records.begin();
            //for (map<string, PII>::iterator iter = records.begin();
                 iter != records.end();
                 ++iter) {
                PII &pii = iter->second;
                pii.second = 0;
            }
            for (int i = start;
                 i + word_length - 1 < S.length();
                 i += word_length) {
                string word = S.substr(i, word_length);
                if (records.find(word) != records.end()) {
                    buffer.push(make_pair(word, i));
                    PII &record = records[word];
                    record.second++;
                    if (record.first < record.second) {
                        while (true) {
                            PSI head = buffer.front();
                            buffer.pop();
                            PII &entry = records[head.first];
                            entry.second--;
                            if (record.first == record.second)
                                break;
                        }
                    }
                    if (buffer.size() == L.size())
                        indices.push_back(buffer.front().second);
                } else {
                    // The substring cannot include word not in dictionary
                    while (!buffer.empty()) {
                        PSI head = buffer.front();
                        buffer.pop();
                        PII &entry = records[head.first];
                        entry.second--;
                    }
                }
            }
        }
        return indices;
    }
};
