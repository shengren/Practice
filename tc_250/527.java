import java.util.*;

public class P8XGraphBuilder {
    int find(int c, int s, int rest_node, int rest_degree, int[] scores) {
        if (rest_node == 0 && rest_degree == 0) return s;
        if (rest_node == 0 || rest_degree == 0) return Integer.MIN_VALUE;
        if (rest_node * c > rest_degree) return Integer.MIN_VALUE;
        int N = scores.length + 1;
        if (c == N) return Integer.MIN_VALUE;
        int ret = Integer.MIN_VALUE;
        for (int i = 0; i <= rest_node && i * c <= rest_degree; ++i) {
            int x = find(c + 1, s + scores[c - 1] * i, rest_node - i, rest_degree - c * i, scores);
            if (ret < x) ret = x;
        }
        return ret;
    }
    public int solve(int[] scores) {
        int N = scores.length + 1;
        return find(1, 0, N, 2 * (N - 1), scores);
    }
}