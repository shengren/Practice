class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        int prefix_length = 0;
        while (true) {
            bool pass = true;
            for (int i = 0; i < strs.size(); ++i)
                if (prefix_length == strs[i].length() ||
                    strs[i][prefix_length] != strs[0][prefix_length]) {
                    pass = false;
                    break;  // Need another break to quit for-loop
                }
            if (!pass)
                break;
            ++prefix_length;
        }
        if (prefix_length == 0)
            return "";
        return strs[0].substr(0, prefix_length);
    }
};
