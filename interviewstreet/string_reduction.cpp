/*
DFS + Prune
without prune, TLE (although the system said WA)
right after touching case 1 or 2, return result
referred https://github.com/kanwei/interviewstreet-solutions/blob/master/stringred/stringred.rb
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

bool done;

char third(char u, char v) {
  return (char)('a' + 3 - (u - 'a') - (v - 'a'));
}

int reduce(string x) {
  if (x.size() == 1) {  // case 1
    done = true;
    return 1;
  }
  if (x.size() == 2 && x[0] == x[1]) {  // case 2
    done = true;
    return 2;
  }
  int ret = x.size();
  for (int i = 1; i < x.size(); ++i)
    if (x[i - 1] != x[i]) {
      string next = x.substr(0, i - 1) + third(x[i - 1], x[i]) + x.substr(i + 1);
      int t = reduce(next);
      if (t < ret)
        ret = t;
      if (done)
        return ret;
    }
  return ret;
}

int main(void) {
  int ncase;
  cin >> ncase;
  while (ncase--) {
    string s;
    cin >> s;
    done = false;
    cout << reduce(s) << endl;
  }

  return 0;
}
