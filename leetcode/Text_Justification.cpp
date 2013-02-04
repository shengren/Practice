class Solution {
    void addSpace(string &s, int n) {
        while (n--) {
            s += ' ';
        }
    }
    string constructLine(vector<string> &words_in_line,
                         int num_space,
                         bool is_last_line) {
        string line = "";
        for (int i = 0; i < words_in_line.size(); ++i) {
            if (i > 0) {
                if (!is_last_line) {
                    int pad = (int)ceil(
                        (double)num_space / (words_in_line.size() - i));
                    addSpace(line, pad);
                    num_space -= pad;
                } else {
                    addSpace(line, 1);
                    num_space -= 1;
                }
            }
            line += words_in_line[i];
        }
        addSpace(line, num_space);  // This line has a single word.
        return line;
    }
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> text;
        for (int i = 0; i < words.size();) {
            vector<string> words_in_line;
            int line_length = 0;
            int num_space = L;
            while (i < words.size()) {
                int length_increment = words[i].length();
                if (line_length != 0)  // not the first word in the line
                    length_increment += 1;
                if (line_length + length_increment <= L) {
                    words_in_line.push_back(words[i]);
                    line_length += length_increment;
                    num_space -= words[i].length();
                    ++i;
                } else {
                    break;
                }
            }
            text.push_back(
                constructLine(words_in_line, num_space, (i == words.size())));
        }
        return text;
    }
};
