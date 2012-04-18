#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <set>

using namespace std;


class EllysJuice {
    public:
        vector<string> getWinners(vector<string> players) {
            set<string> can;
            do {
                map<string, double> record;
                double v = 1.0;
                for (int i = 0; i < players.size(); ++i) {
                    if (i % 2 == 0)
                        v /= 2;
                    if (record.find(players[i]) == record.end()) {
                        record[players[i]] = v;
                    } else {
                        record[players[i]] += v;
                    }
                }
                double max_v = 0.0;
                string winner;
                int count = 0;
                map<string, double>::iterator iter = record.begin();
                for (; iter != record.end(); ++iter) {
                    if (iter->second > max_v) {
                        max_v = iter->second;
                        winner = iter->first;
                        count = 1;
                    } else if (iter->second == max_v) {
                        ++count;
                    }
                }
                if (count == 1)
                    can.insert(winner);
            } while (next_permutation(players.begin(), players.end()));
            vector<string> ret;
            set<string>::iterator iter2 = can.begin();
            for (; iter2 != can.end(); ++iter2)
                ret.push_back(*iter2);
            sort(ret.begin(), ret.end());
            return ret;
        }    
};