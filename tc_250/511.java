public class Zoo {
    public long theCount(int[] answers) {
        int[] num = new int[41];
        for (int i = 0; i < answers.length; ++i) {
            ++num[answers[i]];
        }
        int cur = 0;
        while (num[cur] == 2) {
            ++cur;
        }
        long ret = (1L << cur);
        boolean single = false;
        while (num[cur] == 1) {
        	single = true;
        	++cur;
        }
        while (cur <= 40) {
            if (num[cur] != 0) return 0;
           	++cur;
        }
        return (single ? 2 * ret : ret);
    }
}