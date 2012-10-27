#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int step[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // N, E, S, W

struct Ant {
  int x, y, dir;
  Ant(int _x, int _y, int _dir) {
    x = _x;
    y = _y;
    dir = _dir;
  }
};

class AntsMeet {
public:
  int countAnts(vector<int> x, vector<int> y, string direction) {
    list<Ant> a;
    for (int i = 0; i < x.size(); ++i) {
      int d;
      if (direction[i] == 'N') d = 0;
      else if (direction[i] == 'E') d = 1;
      else if (direction[i] == 'S') d = 2;
      else d = 3;
      a.push_back(Ant(x[i], y[i], d));
    }
    int num_iterations = 2001;
    while (num_iterations--) {
      list<Ant>::iterator it = a.begin();
      for (; it != a.end();) {
        int cx = it->x + step[it->dir][0];
        int cy = it->y + step[it->dir][1];
        int cd = (it->dir + 2) % 4;
        bool collision = false;
        list<Ant>::iterator it2 = it;
        ++it2;
        for (; it2 != a.end(); ++it2)
          if (it2->x == cx && it2->y == cy && it2->dir == cd) {
            collision = true;
            a.erase(it2);
            break;
          }
        if (collision) {
          it = a.erase(it);
        } else {
          ++it;
        }
      }
      
      it = a.begin();
      for (; it != a.end(); ++it) {
        it->x += step[it->dir][0];
        it->y += step[it->dir][1];
      }
      
      it = a.begin();
      for (; it != a.end();) {
        bool collision = false;
        list<Ant>::iterator it2 = it;
        ++it2;
        for (; it2 != a.end();)
          if (it->x == it2->x && it->y == it2->y) {
            collision = true;
            it2 = a.erase(it2);
          } else {
            ++it2;
          }
        if (collision) {
          it = a.erase(it);
        } else {
          ++it;
        }
      }
      
      //cout << num_iterations << " " << a.size() << endl;
    }
    return a.size();
  }
};
