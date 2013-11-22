#include <cstdio>
#include <cstring>

using namespace std;

int num_case, side_len;
char grid[20][21];

bool detect() {
  int min_row = side_len;
  int min_col = side_len;
  int max_row = -1;
  int max_col = -1;

  for (int i = 0; i < side_len; ++i)
    for (int j = 0; j < side_len; ++j)
      if (grid[i][j] == '#') {
        if (min_row > i)
          min_row = i;
        if (max_row < i)
          max_row = i;
        if (min_col > j)
          min_col = j;
        if (max_col < j)
          max_col = j;
      }

  //printf("%d %d %d %d\n", min_row, max_row, min_col, max_col);

  if (max_row - min_row != max_col - min_col)
    return false;

  for (int i = min_row; i <= max_row; ++i)
    for (int j = min_col; j <= max_col; ++j)
      if (grid[i][j] != '#')
        return false;

  return true;
}

int main() {
  scanf("%d", &num_case);
  for (int cid = 1; cid <= num_case; ++cid) {
      scanf("%d", &side_len);
      for (int i = 0; i < side_len; ++i)
        scanf("%s", grid[i]);

      /*printf("\n");
      for (int i = 0; i < side_len; ++i) {
        for (int j = 0; j < side_len; ++j)
          printf("%c", grid[i][j]);
        printf("$\n");
      }*/

      printf("Case #%d: ", cid);
      if (detect())
        printf("YES\n");
      else
        printf("NO\n");
  }

  return 0;
}
