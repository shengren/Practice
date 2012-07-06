import java.util.*;

public class CubeWalking {
    int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public String finalPosition(String movement) {
        int x = 1, y = 1, d = 0;
        for (int i = 0; i < movement.length(); ++i) {
            if (movement.charAt(i) == 'W') {
                x = (x + 3 + dir[d][0]) % 3;
                y = (y + 3 + dir[d][1]) % 3;
            } else if (movement.charAt(i) == 'L') {
                d = (d + 3) % 4;
            } else {
                d = (d + 1) % 4;
            }
        }
        
        System.out.printf("%d %d%n", x, y);

        if (x == 1 && y == 1) {
            return "GREEN";
        } else if ((x + y) % 2 == 0) {
            return "RED";
        } else {
            return "BLUE";
        }
    }
}