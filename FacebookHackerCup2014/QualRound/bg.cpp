#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Player {
  string name;
  int shot_percentage;
  int height;
  int rank;
  int time;
};
vector<Player> all;

bool cmp1(const Player &x, const Player &y) {
  if (x.shot_percentage == y.shot_percentage)
    return x.height > y.height;
  return x.shot_percentage > y.shot_percentage;
}

bool cmp2(int a, int b) {
  if (all[a].time == all[b].time)
    return all[a].rank < all[b].rank;
  return all[a].time < all[b].time;
}

void rotate(vector<int> &field, vector<int> &bench) {
  for (int i = 0; i < field.size(); ++i)
    all[field[i]].time++;
  sort(field.begin(), field.end(), cmp2);
  sort(bench.begin(), bench.end(), cmp2);
  if (bench.size() > 0)
    swap(field[field.size() - 1], bench[0]);
}

int main() {
  int num_case, num_player, num_min, team_size;
  cin >> num_case;

  for (int cid = 1; cid <= num_case; ++cid) {
    cin >> num_player >> num_min >> team_size;

    all.clear();
    for (int i = 0; i < num_player; ++i) {
      Player p;
      cin >> p.name >> p.shot_percentage >> p.height;
      all.push_back(p);
    }

    sort(all.begin(), all.end(), cmp1);

    for (int i = 0; i < num_player; ++i) {
      all[i].rank = i + 1;
      all[i].time = 0;
    }

    vector<int> field1;
    vector<int> bench1;
    vector<int> field2;
    vector<int> bench2;
    for (int i = 0; i < num_player; ++i)
      if (i % 2 == 0) {
        if (field1.size() < team_size)
          field1.push_back(i);
        else
          bench1.push_back(i);
      } else {
        if (field2.size() < team_size)
          field2.push_back(i);
        else
          bench2.push_back(i);
      }

    /*for (int i = 0; i < all.size(); ++i)
      cout << all[i].name << " " << all[i].shot_percentage << " " << all[i].height << " " << all[i].rank << " " << all[i].time << endl;
    cout << endl;
    for (int i = 0; i < field1.size(); ++i)
      cout << field1[i] << endl;
    cout << endl;
    for (int i = 0; i < bench1.size(); ++i)
      cout << bench1[i] << endl;
    cout << endl;
    for (int i = 0; i < field2.size(); ++i)
      cout << field2[i] << endl;
    cout << endl;
    for (int i = 0; i < bench2.size(); ++i)
      cout << bench2[i] << endl;*/

    while (num_min--) {
      rotate(field1, bench1);
      rotate(field2, bench2);
    }

    vector<string> res;
    for (int i = 0; i < team_size; ++i) {
      res.push_back(all[field1[i]].name);
      res.push_back(all[field2[i]].name);
    }
    sort(res.begin(), res.end());

    cout << "Case #" << cid << ":";
    for (int i = 0; i < res.size(); ++i)
      cout << " " << res[i];
    cout << endl;
  }

  return 0;
}
