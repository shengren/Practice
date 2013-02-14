typedef pair<int, vector<string> > PIVS;

class Solution {
    unordered_map<string, PIVS> graph;
    int min_dist;
    int word_length;
    vector<vector<string> > sequences;
    void enumerate(string end, vector<string> &seq) {
        if (seq.size() == min_dist) {
            if (seq.back() == end)
                sequences.push_back(seq);
            return;
        }
        const vector<string> &nexts = graph[seq.back()].second;
        for (int i = 0; i < nexts.size(); ++i) {
            seq.push_back(nexts[i]);
            enumerate(end, seq);
            seq.pop_back();
        }
    }
public:
    vector<vector<string> > findLadders(string start, string end,
                                        unordered_set<string> &dict) {
        graph.clear();
        min_dist = -1;
        word_length = start.length();
        queue<string> checking;
        graph[start] = make_pair(1, vector<string>());
        checking.push(start);
        while (!checking.empty()) {
            string current = checking.front();
            checking.pop();
            PIVS &pivs = graph[current];
            if (min_dist != -1 && pivs.first == min_dist)
                continue;
            for (int i = 0; i < word_length; ++i)
                for (int j = 0; j < 26; ++j) {
                    string next = current;
                    next[i] = 'a' + j;
                    if (next == current)
                        continue;
                    if (next != end && dict.find(next) == dict.end())
                        continue;
                    if (next == end) {  // 'end' may be equal to 'start'
                        if (min_dist == -1)
                            min_dist = pivs.first + 1;
                        pivs.second.push_back(next);
                        continue;
                    }
                    if (graph.find(next) != graph.end()) {
                        if (graph[next].first != pivs.first + 1)  // cycle
                            continue;
                    } else {
                        graph[next] = make_pair(pivs.first + 1,
                                                vector<string>());
                        checking.push(next);
                    }
                    pivs.second.push_back(next);
                }
        }
        sequences.clear();
        if (min_dist != -1) {
            vector<string> seq;
            seq.push_back(start);
            enumerate(end, seq);
        }
        return sequences;
    }
};
