class Solution {
    string removeSpaces(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < s.length() && s[i] == ' ')
            ++i;
        while (j >= 0 && s[j] == ' ')
            --j;
        if (i <= j)
            return s.substr(i, j - i + 1);
        return "";
    }
    bool isValidInteger(string s, bool canHasSign, bool canBeEmpty) {
        if (s == "")
            return canBeEmpty;
        if (canHasSign && (s[0] == '+' || s[0] == '-'))
            return isValidInteger(s.substr(1), false, canBeEmpty);
        for (int i = 0; i < s.length(); ++i)
            if (!(s[i] >= '0' && s[i] <= '9'))
                return false;
        return true;
    }
public:
    bool isNumber(const char *s) {
        string str(s);
        // Remove leading and ending spaces
        str = removeSpaces(str);
        // No meaningful part
        if (str == "")
            return false;
        // More than one meaningful part
        if (str.find_first_of(' ') != string::npos)
            return false;
        unsigned pos;
        // Scientific notation
        if ((pos = str.find_first_of('e')) != string::npos) {
            // Check the second part
            if (isValidInteger(str.substr(pos + 1), true, false)) {
                // Check the first part
                str = str.substr(0, pos);
                // The first part of scientific notation can be decimal.
                if ((pos = str.find_first_of('.')) != string::npos) {
                    // The second part of decimal is empty.
                    if (pos == str.length() - 1) {
                        return isValidInteger(str.substr(0, pos), true, false);
                    } else {
                        return isValidInteger(str.substr(0, pos), true, true) &&
                               isValidInteger(str.substr(pos + 1), false, false);
                    }
                } else {
                    return isValidInteger(str, true, false);
                }
            } else {
                return false;
            }
        }
        // Decimal
        if ((pos = str.find_first_of('.')) != string::npos) {
            // The second part of decimal is empty.
            if (pos == str.length() - 1) {
                return isValidInteger(str.substr(0, pos), true, false);
            } else {
                return isValidInteger(str.substr(0, pos), true, true) &&
                       isValidInteger(str.substr(pos + 1), false, false);
            }
        }
        // Integer
        if (isValidInteger(str, true, false))
            return true;
        return false;
    }
};
