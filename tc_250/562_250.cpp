#include <vector>
#include <string>
#include <cmath>

using namespace std;

char canvas[50][50];

class PastingPaintingDivOne {
 public:
  int R, C, M;
  long long cr, cg, cb;
  long long r, g, b;
  
  void paste(vector<string> &bd, bool isFirst) {
    if (isFirst) {
      for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
          canvas[i][j] = bd[i][j];
    } else {
      for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
          if (i < R - 1 && j < C - 1)
	        canvas[i][j] = canvas[i + 1][j + 1];
	      else
	        canvas[i][j] = '.';
	  for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
          if (bd[i][j] != '.')
            canvas[i][j] = bd[i][j];
    }
  }
  
  void countFirst(long long &r, long long &g, long long &b) {
    r = g = b = 0;
  	for (int i = 0; i < R; ++i) {
  	  if (canvas[i][0] == 'R') ++r;
  	  else if (canvas[i][0] == 'G') ++g;
  	  else if (canvas[i][0] == 'B') ++b;
  	}
  	for (int j = 1; j < C; ++j) {
      if (canvas[0][j] == 'R') ++r;
  	  else if (canvas[0][j] == 'G') ++g;
  	  else if (canvas[0][j] == 'B') ++b;
  	}
  }
  
  void countRest(long long &r, long long &g, long long &b) {
    r = g = b = 0;
    for (int i = 1; i < R; ++i)
      for (int j = 1; j < C; ++j)
        if (canvas[i][j] == 'R') ++r;
    	else if (canvas[i][j] == 'G') ++g;
  	    else if (canvas[i][j] == 'B') ++b;
  }

  vector<long long> countColors(vector <string> bd, int T) {
    R = bd.size();
    C = bd[0].size();
    M = max(R, C);
    
    paste(bd, true);
    countFirst(r, g, b);
    cr = r; cg = g; cb = b;
    
    int t = 2;
    while (t <= T && t <= M) {
      paste(bd, false);
      countFirst(r, g, b);
      cr += r; cg += g; cb += b;
      ++t;
    }
    
    if (t > T) {
      countRest(r, g, b);
      cr += r; cg += g; cb += b;
      vector<long long> ret;
      ret.push_back(cr);
      ret.push_back(cg);
      ret.push_back(cb);
      return ret;
    }
    
    paste(bd, false);
    countFirst(r, g, b);
    cr += r * (T - M); cg += g * (T - M); cb += b * (T - M);
    
    countRest(r, g, b);
    cr += r; cg += g; cb += b;
    vector<long long> ret;
    ret.push_back(cr);
    ret.push_back(cg);
    ret.push_back(cb);
    return ret;
  }
};
