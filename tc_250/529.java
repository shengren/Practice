import java.util.*;

class Name implements Comparable {
    public String origin;
    public String name;
    public int num;
    int convert(String r) {
        if (r.length() == 0) return 0;
        if (r.equals("L")) return 50;
        if (r.length() >= 2 && r.substring(0, 2).equals("XL")) return 40 + convert(r.substring(2));
        if (r.length() >= 3 && r.substring(0, 3).equals("XXX")) return 30 + convert(r.substring(3));
        if (r.length() >= 2 && r.substring(0, 2).equals("XX")) return 20 + convert(r.substring(2));
        if (r.substring(0, 1).equals("X")) return 10 + convert(r.substring(1));
        if (r.equals("I")) return 1;
        if (r.equals("II")) return 2;
        if (r.equals("III")) return 3;
        if (r.equals("IV")) return 4;
        if (r.equals("V")) return 5;
        if (r.equals("VI")) return 6;
        if (r.equals("VII")) return 7;
        if (r.equals("VIII")) return 8;
        if (r.equals("IX")) return 9;
        return Integer.MAX_VALUE;
    }
    public Name(String input) {
        origin = input;
        String[] s = origin.split(" ");
        name = s[0];
        num = convert(s[1]);
    }
    public int compareTo(Object o) {
        Name x = (Name)o;
        if (name.equals(x.name)) return num - x.num;
        return name.compareTo(x.name);
    }
}

public class KingSort {
	public String[] getSortedList(String[] kings) {
	    Name[] m = new Name[kings.length];
		for (int i = 0; i < kings.length; ++i) {
		    m[i] = new Name(kings[i]);
		}
		Arrays.sort(m);
		String[] ret = new String[kings.length];
		for (int i = 0; i < m.length; ++i) {
		    ret[i] = m[i].origin;
		}
		return ret;
	}
}