import java.util.*;

public class Cut {
	public int getMaximum(int[] eelLengths, int maxCuts) {
		int ret = 0;
		Arrays.sort(eelLengths);
		for (int i = 0; i < eelLengths.length; ++i)
			if (eelLengths[i] == 10)
			    ret++;
		for (int i = 0; i < eelLengths.length; ++i)
			if (eelLengths[i] % 10 == 0 && eelLengths[i] > 10) {
			    int x = eelLengths[i] / 10 - 1;
			    x = Math.min(x, maxCuts);
			    ret += x;
			    if ((x + 1) * 10 == eelLengths[i]) ret++;
			    maxCuts -= x;
			    if (maxCuts == 0) return ret;
			}
	    for (int i = 0; i < eelLengths.length; ++i)
			if (eelLengths[i] % 10 != 0 && eelLengths[i] > 10) {
			    int x = eelLengths[i] / 10;
			    x = Math.min(x, maxCuts);
			    ret += x;
			    maxCuts -= x;
			    if (maxCuts == 0) return ret;
		    }
		return ret;
	}
}