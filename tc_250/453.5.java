import java.util.*;

public class MazeMaker {
    public int longestPath(String[] maze, int startRow, int startCol, int[] moveRow, int[] moveCol) {
        int numRow = maze.length;
        int numCol = maze[0].length();
        int[][] numStep = new int[numRow][numCol];
        for (int i = 0; i < numRow; ++i)
            for (int j = 0; j < numCol; ++j)
                numStep[i][j] = Integer.MAX_VALUE;

        numStep[startRow][startCol] = 0;
        Queue<Position> q = new LinkedList<Position>();
        q.add(new Position(startRow, startCol));

        while (q.size() > 0) {
            Position p = q.poll();
            for (int i = 0; i < moveRow.length; ++i) {
                int nx = p.x + moveRow[i];
                int ny = p.y + moveCol[i];
                if (nx >= 0 && nx < numRow && ny >= 0 && ny < numCol && maze[nx].charAt(ny) == '.' &&
                    numStep[nx][ny] == Integer.MAX_VALUE) {
                    numStep[nx][ny] = 1 + numStep[p.x][p.y];
                    q.add(new Position(nx, ny));
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < numRow; ++i)
            for (int j = 0; j < numCol; ++j)
                if (maze[i].charAt(j) == '.')
                    ret = Math.max(ret, numStep[i][j]);

        return (ret == Integer.MAX_VALUE) ? -1 : ret;
    }
}

class Position {
    int x, y;
    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}