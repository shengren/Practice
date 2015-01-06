struct State {
  int lowest;
  int health;
  
  State() : lowest(INT_MIN), health(INT_MIN) {}
  State(int l, int h) : lowest(l), health(h) {}
};

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int M = dungeon.size();
    int N = dungeon[0].size();
    vector<vector<State>> MaxLowest(M, vector<State>(N));
    vector<vector<State>> MaxHealth(M, vector<State>(N));

    if (dungeon[0][0] < 0) {
      MaxLowest[0][0] = MaxHealth[0][0] = State(dungeon[0][0], dungeon[0][0]);
    } else {
      MaxLowest[0][0] = MaxHealth[0][0] = State(0, dungeon[0][0]);
    }

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i == 0 && j == 0) continue;

        if (i > 0) {
          int h = MaxLowest[i - 1][j].health + dungeon[i][j];
          int l = (MaxLowest[i - 1][j].lowest < h) ? MaxLowest[i - 1][j].lowest : h;
          if (MaxLowest[i][j].lowest < l || (MaxLowest[i][j].lowest == l && MaxLowest[i][j].health < h))
            MaxLowest[i][j] = State(l, h);
          if (MaxHealth[i][j].health < h || (MaxHealth[i][j].health == h && MaxHealth[i][j].lowest < l))
            MaxHealth[i][j] = State(l, h);

          h = MaxHealth[i - 1][j].health + dungeon[i][j];
          l = (MaxHealth[i - 1][j].lowest < h) ? MaxHealth[i - 1][j].lowest : h;
          if (MaxLowest[i][j].lowest < l || (MaxLowest[i][j].lowest == l && MaxLowest[i][j].health < h))
            MaxLowest[i][j] = State(l, h);
          if (MaxHealth[i][j].health < h || (MaxHealth[i][j].health == h && MaxHealth[i][j].lowest < l))
            MaxHealth[i][j] = State(l, h);
        }

        if (j > 0) {
          int h = MaxLowest[i][j - 1].health + dungeon[i][j];
          int l = (MaxLowest[i][j - 1].lowest < h) ? MaxLowest[i][j - 1].lowest : h;
          if (MaxLowest[i][j].lowest < l || (MaxLowest[i][j].lowest == l && MaxLowest[i][j].health < h))
            MaxLowest[i][j] = State(l, h);
          if (MaxHealth[i][j].health < h || (MaxHealth[i][j].health == h && MaxHealth[i][j].lowest < l))
            MaxHealth[i][j] = State(l, h);

          h = MaxHealth[i][j - 1].health + dungeon[i][j];
          l = (MaxHealth[i][j - 1].lowest < h) ? MaxHealth[i][j - 1].lowest : h;
          if (MaxLowest[i][j].lowest < l || (MaxLowest[i][j].lowest == l && MaxLowest[i][j].health < h))
            MaxLowest[i][j] = State(l, h);
          if (MaxHealth[i][j].health < h || (MaxHealth[i][j].health == h && MaxHealth[i][j].lowest < l))
            MaxHealth[i][j] = State(l, h);
        }
      }
    }
    
    return 1 - max(MaxLowest[M - 1][N - 1].lowest, MaxHealth[M - 1][N - 1].lowest);
  }
};