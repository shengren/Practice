import java.util.*;

public class Solution {
    public String simplifyPath(String path) {
        path = "/" + path + "/";
        String[] name = path.split("/");
        Deque<String> q = new LinkedList();
        for (int i = 0; i < name.length; ++i) {
            if (name[i].equals("..")) {
                if (!q.isEmpty())
                    q.removeLast();
            } else if (name[i].length() > 0 && !name[i].equals(".")) {
                q.add(name[i]);
            }
        }
        if (q.isEmpty()) return "/";
        String ret = "";
        Iterator<String> it = q.iterator();
        while (it.hasNext()) {
            ret += "/" + it.next();
        }
        return ret;
    }
}