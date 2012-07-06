public class TheQuestionsAndAnswersDivOne {
    int nQ, nY, nN, res, tmp;
    int[] n = new int[9];

    public int find(int questions, String[] answers) {
        nQ = questions;
        nY = nN = 0;
        for (int i = 0; i < answers.length; ++i) {
            if (answers[i].equals("Yes")) ++nY;
            else ++nN;
        }
        res = 0;
        gen(0, 0, 0);
        return res;
    }

    private void gen(int cur, int numY, int numN) {
        if (cur == nQ) {
        	if (nY != 0 && numY == 0) return;
            if (nN != 0 && numN == 0) return;
            //System.out.printf("%d %d%n", numY, numN);
            res += comp(numY, nY) * comp(numN, nN);
            return;
        }
        if (numY < nY) {
            gen(cur + 1, numY + 1, numN);
        }
        if (numN < nN) {
            gen(cur + 1, numY, numN + 1);
        }
    }

    private int comp(int a, int b) {
    	if (b == 0) return 1;
        tmp = 0;
        gen2(0, a, b, b);
        return tmp;
    }

    private void gen2(int cur, int len, int rest, int total) {
        if (cur == len) {
        	//System.out.print("n: ");
        	//for (int i = 0; i < len; ++i) System.out.printf("%d ", n[i]);
        	//System.out.println();
            int p = 1;
            for (int i = 0; i < len; ++i) {
                p *= comp2(n[i], total);
                total -= n[i];
            }
            tmp += p;
            return;
        }
        if (cur == len - 1) {
        	n[cur] = rest;
        	gen2(cur + 1, len, 0, total);
        }
        else {
    	    for (int i = 1; rest - i >= len - cur - 1; ++i) {
	            n[cur] = i;
            	gen2(cur + 1, len, rest - i, total);
        	}
        }
    }
    
    private int comp2(int a, int b) {
        int num = 1, den = 1;
        for (int i = 1; i <= a; ++i) {
            num *= (b - i + 1);
            den *= i;
        }
        return num / den;
    }
}