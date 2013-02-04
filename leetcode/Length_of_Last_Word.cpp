class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = strlen(s);
        int last_word_length = 0;
        int count = 0;
        for (int i = 0; i <= length; ++i)
            if (i == length || s[i] == ' ') {
                if (count > 0)
                    last_word_length = count;
                count = 0;
            } else {
                ++count;
            }
        return last_word_length;
    }
};
