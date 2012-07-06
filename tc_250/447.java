import java.util.*;

public class KnightsTour {
    int[][] dir = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    String[] board;
    int[][] step;
    int[][] db = new int[8][8];

    public int visitedPositions(String[] board) {
        this.board = board;
        step = new int[8][8];
        int x = 0, y = 0;

        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j) {
                if (board[i].charAt(j) == 'K') {
                    step[i][j] = 1;
                    x = i;
                    y = j;
                } else {
                    step[i][j] = Integer.MAX_VALUE;
                }
            }

        int numStep = 1;
        boolean flag = true;
        while (flag) {
            flag = false;

            //clearDB();

            int lowestAccessibility = 9;
            int choice = -1;
            for (int i = 0; i < 8; ++i) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8
                    && board[nx].charAt(ny) == '.'
                    && step[nx][ny] == Integer.MAX_VALUE) {
                    flag = true;
                    int accessibility = calculateAccessibility(nx, ny);
                    //db[nx][ny] = accessibility;
                    if (accessibility < lowestAccessibility) {
                        choice = i;
                        lowestAccessibility = accessibility;
                    }
                }
            }

            if (flag) {
                x += dir[choice][0];
                y += dir[choice][1];
                step[x][y] = ++numStep;
            }

            //printDB();
        }
        
        //printBoard();

        return numStep;
    }

    int calculateAccessibility(int x, int y) {
        int ret = 0;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8
                && board[nx].charAt(ny) == '.'
                && step[nx][ny] == Integer.MAX_VALUE) {
                ++ret;
            }
        }
        return ret;
    }

    void printBoard() {
        System.out.println();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i].charAt(j) == '*') {
                    System.out.print('*');
                } else {
                    if (step[i][j] == Integer.MAX_VALUE) System.out.print('.');
                    else System.out.print('#');
                }
            }
            System.out.println();
        }
    }

    void clearDB() {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                db[i][j] = -1;
    }
    
    void printDB() {
        System.out.println();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i].charAt(j) == '*') {
                    System.out.print('*');
                } else {
                    if (db[i][j] != -1) {
                        System.out.print(db[i][j]);
                    } else {
                        if (step[i][j] == Integer.MAX_VALUE) System.out.print('.');
                        else System.out.print('#');
                    }
                }
            }
            System.out.println();
        }
    }
}