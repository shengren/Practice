class Solution {
public:
    bool isValid(string s) {
        stack<int> a;  // '('
        stack<int> b;  // '{'
        stack<int> c;  // '['
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '(') {
                a.push(i);
            } else if (s[i] == '{') {
                b.push(i);
            } else if (s[i] == '[') {
                c.push(i);
            } else if (s[i] == ')') {
                if (a.empty())
                    return false;
                int x = a.top();
                a.pop();
                if ((!b.empty() && b.top() > x) ||
                    (!c.empty() && c.top() > x))
                    return false;
            } else if (s[i] == '}') {
                if (b.empty())
                    return false;
                int x = b.top();
                b.pop();
                if ((!a.empty() && a.top() > x) ||
                    (!c.empty() && c.top() > x))
                    return false;
            } else if (s[i] == ']') {
                if (c.empty())
                    return false;
                int x = c.top();
                c.pop();
                if ((!a.empty() && a.top() > x) ||
                    (!b.empty() && b.top() > x))
                    return false;
            }
        if (!a.empty() || !b.empty() || !c.empty())
            return false;
        return true;
    }
};
