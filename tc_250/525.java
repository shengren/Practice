import java.util.*;

public class DropCoins {
  public static int getMinimum(String board[], int K) {
    int R = board.length;
    int C = board[0].length();
    int[][] scan = new int[R][C];
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j) {
        scan[i][j] = (board[i].charAt(j) == 'o') ? 1: 0;
        if (j > 0) scan[i][j] += scan[i][j - 1];
      }
    for (int i = 1; i < R; ++i)
      for (int j = 0; j < C; ++j) {
        scan[i][j] += scan[i - 1][j];
      }
    int ret = -1;
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        for (int p = i; p < R; ++p)
          for (int q = j; q < C; ++q) {
            int cand = scan[p][q];
            if (i > 0) cand -= scan[i - 1][q];
            if (j > 0) cand -= scan[p][j - 1];
            if (i > 0 && j > 0) cand += scan[i - 1][j - 1];
            if (cand == K) {
              int num_op = 0;
              int smaller = Math.min(i, R - 1 - p);
              int bigger = Math.max(i, R - 1 - p);
              num_op += smaller * 2 + bigger;
              smaller = Math.min(j, C - 1 - q);
              bigger = Math.max(j, C - 1 - q);
              num_op += smaller * 2 + bigger;
              //System.out.printf("%d %d %d %d\n", i, j, p, q);
              if (ret == -1 || ret > num_op) {
                ret = num_op;
                //System.out.printf("%d %d %d %d\n", i, j, p, q);
              }
            }
          }
    return ret;
  }
}