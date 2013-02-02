class Solution {
    vector<string> possible_ips;
    string no_dots;
    bool isValid(string n) {
        istringstream iss(n);
        int num;
        iss >> num;
        return num <= 255;
    }
    void enumerateIP(int start, int idx, string current) {
        if (idx == 4) {
            if (start == no_dots.length())
                possible_ips.push_back(current);
            return;
        }
        if (start < no_dots.length()) {
            string next = current;
            if (idx > 0)
                next += ".";
            next += no_dots.substr(start, 1);
            enumerateIP(start + 1, idx + 1, next);
        }
        // The first digit cannot be 0. Forgot at first.
        if (start + 1 < no_dots.length() && no_dots[start] != '0') {
            string next = current;
            if (idx > 0)
                next += ".";
            next += no_dots.substr(start, 2);
            enumerateIP(start + 2, idx + 1, next);
        }
        // The first digit cannot be 0. Forgot at first.
        if (start + 2 < no_dots.length() && no_dots[start] != '0') {
            if (isValid(no_dots.substr(start, 3))) {
                string next = current;
                if (idx > 0)
                    next += ".";
                next += no_dots.substr(start, 3);
                enumerateIP(start + 3, idx + 1, next);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        no_dots = s;
        possible_ips.clear();
        enumerateIP(0, 0, "");
        return possible_ips;
    }
};
