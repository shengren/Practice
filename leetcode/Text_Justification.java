import java.util.*;

public class Solution {
    String generateLine(ArrayList<String> w, boolean last, int L) {
        String ret = "";
        if (w.size() == 1) {
            ret = w.iterator().next();
        } else if (last) {
            ListIterator<String> it = w.listIterator();
            ret = it.next();
            while (it.hasNext()) {
                ret += " ";
                ret += it.next();
            }
        } else {
            int[] pad = new int[w.size() - 1];
            int rest = 0;
            ListIterator<String> it = w.listIterator();
            while (it.hasNext()) {
                rest += it.next().length();
            }
            rest = L - rest;
            while (rest > 0) {
                for (int i = 0; i < pad.length; ++i) {
                    pad[i]++;
                    rest--;
                    if (rest == 0) break;
                }
            }
            it = w.listIterator();
            ret = it.next();
            int p = 0;
            while (it.hasNext()) {
                for (int i = 0; i < pad[p]; ++i) ret += " ";
                ++p;
                ret += it.next();
            }
        }
        int extra = L - ret.length();
        while (extra > 0) {
            ret += " ";
            --extra;
        }
        return ret;
    }
    public ArrayList<String> fullJustify(String[] words, int L) {
        ArrayList<String> ret = new ArrayList<String>();
        int i = 0;
        while (i < words.length) {
            ArrayList<String> line = new ArrayList<String>();
            int len = 0;
            while (i < words.length) {
                int extra = (line.size() == 0) ? 0 : 1;
                if (len + extra + words[i].length() <= L) {
                    len += extra + words[i].length();
                    line.add(words[i]);
                } else {
                    break;
                }
                ++i;
            }
            boolean last = (i == words.length) ? true : false;
            ret.add(generateLine(line, last, L));
        }
        return ret;
    }
}
