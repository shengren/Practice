import java.util.*;

public class MaxTriangle {
    public double calculateArea(int A, int B) {
        ArrayList<Position> plsA = findAllPositions(A);
        if (plsA.size() == 0) return -1.0;
        ArrayList<Position> plsB = findAllPositions(B);
        if (plsB.size() == 0) return -1.0;

        //System.out.println("plsA:");
        //for (Position p : plsA) System.out.printf("  %d %d%n", p.x, p.y);
        //System.out.println("plsB:");
        //for (Position p : plsB) System.out.printf("  %d %d%n", p.x, p.y);

        double maxArea = 0.0;
        for (int i = 0; i < plsA.size(); ++i) {
            Position pA = plsA.get(i);
            for (int j = 0; j < plsB.size(); ++j) {
                Position pB = plsB.get(j);
                double area = calculateArea(pA.x, pA.y, pB.x, pB.y);
                maxArea = Math.max(maxArea, area);
                area = calculateArea(pA.x, pA.y, -pB.x, pB.y);
                maxArea = Math.max(maxArea, area);
                area = calculateArea(pA.x, pA.y, -pB.x, -pB.y);
                maxArea = Math.max(maxArea, area);
                area = calculateArea(pA.x, pA.y, pB.x, -pB.y);
                maxArea = Math.max(maxArea, area);

                area = calculateArea(pA.x, pA.y, pB.y, pB.x);
                maxArea = Math.max(maxArea, area);
                area = calculateArea(pA.x, pA.y, -pB.y, pB.x);
                maxArea = Math.max(maxArea, area);
                area = calculateArea(pA.x, pA.y, -pB.y, -pB.x);
                maxArea = Math.max(maxArea, area);
                area = calculateArea(pA.x, pA.y, pB.y, -pB.x);
                maxArea = Math.max(maxArea, area);
            }
        }

        return maxArea;
    }

    ArrayList<Position> findAllPositions(int s) {
        ArrayList<Position> ret = new ArrayList<Position>();
        int range = (int)Math.sqrt(s * 0.5);
        for (int i = 0; i <= range; ++i) {
            int j = (int)Math.sqrt((double)s - i * i);
            if (s == i * i + j * j) {
                ret.add(new Position(i, j));
            }
        }
        return ret;
    }

    double calculateArea(double ax, double ay, double bx, double by) {
        double a = gg(0, 0, bx, by);
        double b = gg(0, 0, ax, ay);
        double c = gg(ax, ay, bx, by);
        double s = 0.5 * (a + b + c);
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double gg(double ax, double ay, double bx, double by) {
        return Math.sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    }
}

class Position {
    double x, y;
    public Position(double x, double y) {
        this.x = x;
        this.y = y;
    }
}