#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, bool> table;  // true: win state

bool inc(string s) {
  for (int i = 1; i < s.size(); ++i)
    if (s[i - 1] > s[i])
      return false;
  return true;
}

bool check(string s) {
  if (table.find(s) != table.end())
    return table[s];

  for (int i = 0; i < s.size(); ++i) {
    string next = "";
    for (int j = 0; j < s.size(); ++j)
      if (i != j) {
        if (s[j] > s[i])
          next += s[j] - 1;
        else
          next += s[j];
      }
    if (inc(next)) {
      table[s] = true;
      return true;
    }
    if (!check(next)) {
      table[s] = true;
      return true;
    }
  }

  table[s] = false;
  return false;
}

int main(void) {
  table["ab"] = table["ba"] = true;
  table["abc"] = table["acb"] = table["bac"] = table["bca"] = table["cab"] = true;
  table["cba"] = false;
  string base = "abc";
  for (int i = 3; i < 15; ++i) {
    base += 'a' + i;
    table[base] = true;
  }

  int ncase;
  cin >> ncase;
  while (ncase--) {
    int n;
    cin >> n;
    string s = "";
    while (n--) {
      int x;
      cin >> x;
      s += 'a' + x - 1;
    }

    if (check(s))
      cout << "Alice" << endl;
    else
      cout << "Bob" << endl;
  }

  return 0;
}
