typedef pair<string, int> PSI;

class Solution {
    map<PSI, int> cache;
    int measure(string s, int k, string t) {
        if (cache.find(make_pair(s, k)) != cache.end())
            return cache[make_pair(s, k)];
        if (k == t.length()) {
            int distance = s.length();
            cache[make_pair(s, k)] = distance;
            return distance;
        }
        if (s == "") {
            int distance = t.length() - k;
            cache[make_pair(s, k)] = distance;
            return distance;
        }
        if (s[0] == t[k]) {
            int distance = measure(s.substr(1), k + 1, t);
            cache[make_pair(s, k)] = distance;
            return distance;
        } else {
            int min_distance = 987654321;
            int distance = 1 + measure(s, k + 1, t);  // Insert
            if (min_distance > distance)
                min_distance = distance;
            distance = 1 + measure(s.substr(1), k + 1, t);  // Replace
            if (min_distance > distance)
                min_distance = distance;
            distance = 1 + measure(s.substr(1), k, t);  // Delete
            if (min_distance > distance)
                min_distance = distance;
            cache[make_pair(s, k)] = min_distance;
            return min_distance;
        }
    }
public:
    int minDistance(string word1, string word2) {
        cache.clear();
        return measure(word1, 0, word2);
    }
};
