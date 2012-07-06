import java.util.*;

public class Underprimes {
    int numPrime = 0;
    int[] prime = new int[10000];

    public int howMany(int A, int B) {
        findPrimes();

        ArrayList[] p = new ArrayList[2];
        p[0] = new ArrayList<Integer>();
        p[1] = new ArrayList<Integer>();

        for (int i = 0; i < numPrime; ++i) {
            if (prime[i] <= B) {
                p[0].add(prime[i]);
            } else {
                break;
            }
        }

        int ret = 0;
        int step = 1;

        while (true) {
            int to = step % 2;
            int from = 1 - to;
            if (p[from].isEmpty()) break;
            p[to].clear();
            
            /*System.out.printf("%d :", step);
            for (int i = 0; i < p[from].size(); ++i) {
            	System.out.printf(" %d", (Integer)p[from].get(i));
            }
            System.out.println();*/
            
            for (int i = 0; i < p[from].size(); ++i) {
                int cur = (Integer)p[from].get(i);
                int pre = -1;
                if (i > 0) pre = (Integer)p[from].get(i - 1);
                if (i == 0 || cur > pre) {
                    if ((step == 2) || (step == 3) || (step == 5)
                        || (step == 7) || (step == 11) || (step == 13)) {
                        if (cur >= A) ++ret;
                    }
                    for (int j = 0; j < numPrime; ++j) {
                        if (cur * prime[j] <= B) {
                            p[to].add(cur * prime[j]);
                        } else {
                            break;
                        }
                    }
                }
            }
            Collections.sort(p[to]);
            ++step;
        }

        return ret;
    }
    
    void findPrimes() {
        boolean[] isNotPrime = new boolean[100001];
        for (int i = 2; i <= 100000; ++i) {
            if (!isNotPrime[i]) {
                prime[numPrime++] = i;
                for (int j = i; j <= 100000; j += i) isNotPrime[j] = true; 
            }
        }
        //System.out.println(numPrime);
    }
}