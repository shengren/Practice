#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Coor {
  int x, y;
  Coor(int _x, int _y) {
    x = _x;
    y = _y;
  }
  bool operator<(const Coor &rhs) const {
    if (x == rhs.x) return y < rhs.y;
    return x < rhs.x;
  }
};

int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

class RotatingBot {
public:
  int minArea(vector<int> moves) {
    Coor c(0, 0);
    int b[4];  // r, t, l, b
    b[0] = b[1] = b[2] = b[3] = 0;
    bool t[4];
    t[0] = t[1] = t[2] = t[3] = false;
    set<Coor> visited;
    visited.insert(c);
    for (int i = 0; i < moves.size(); ++i) {
      //cout << i << endl;
      int d = i % 4;
      for (int j = 1; j <= moves[i]; ++j) {
        c.x += dir[d][0];
        c.y += dir[d][1];
        if (visited.find(c) != visited.end()) {
          return -1;
        }
        if (t[d]) {
          if (d == 0 && c.y > b[0]) return -1;
          if (d == 1 && c.x < b[1]) return -1;
          if (d == 2 && c.y < b[2]) return -1;
          if (d == 3 && c.x > b[3]) return -1;
        }
        visited.insert(c);
        if (!t[0] && b[0] < c.y) b[0] = c.y;
        if (!t[1] && b[1] > c.x) b[1] = c.x;
        if (!t[2] && b[2] > c.y) b[2] = c.y;
        if (!t[3] && b[3] < c.x) b[3] = c.x;
      }
      Coor nc(c.x + dir[d][0], c.y + dir[d][1]);
      if (i < moves.size() - 1) {
        if (d == 0 && c.y < b[0]) {
          if (visited.find(nc) == visited.end())
            return -1;
        }
        if (d == 1 && c.x > b[1]) {
          if (visited.find(nc) == visited.end())
            return -1;
        }
        if (d == 2 && c.y > b[2]) {
          if (visited.find(nc) == visited.end())
            return -1;
        }
        if (d == 3 && c.x < b[3]) {
          if (visited.find(nc) == visited.end())
            return -1;
        }
      }
      if (!t[d]) t[d] = true;
    }
    return (b[3] - b[1] + 1) * (b[0] - b[2] + 1);
  }
};
