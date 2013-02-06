class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len_haystack = strlen(haystack);
        int len_needle = strlen(needle);
        for (int i = 0; i <= len_haystack - len_needle; ++i) {
            bool flag = true;
            for (int j = 0; j < len_needle; ++j)
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            if (flag)
                return haystack + i;
        }
        return NULL;
    }
};
