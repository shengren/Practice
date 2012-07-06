import java.util.*;

public class NotTwo {
    int[][] dir = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
    public int maxStones(int width, int height) {
        boolean[][] b = new boolean[height][width];
        int ret = 0;
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                if (!b[i][j]) {
                    ++ret;
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if (nx >= 0 && nx < height && ny >= 0 && ny < width)
                            b[nx][ny] = true;
                    }
                }
        return ret;
    }
}