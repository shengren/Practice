string key[10] = {" ",
                  "",
                  "abc",
                  "def",
                  "ghi",
                  "jkl",
                  "mno",
                  "pqrs",
                  "tuv",
                  "wxyz"
                  };

class Solution {
    vector<string> combinations;
    void generate(string digits, int k, string current) {
        if (k == digits.length()) {
            combinations.push_back(current);
            return;
        }
        int i = digits[k] - '0';
        if (i == 1) {
            generate(digits, k + 1, current);
            return;
        }
        for (int j = 0; j < key[i].length(); ++j)
            generate(digits, k + 1, current + key[i][j]);
    }
public:
    vector<string> letterCombinations(string digits) {
        combinations.clear();
        generate(digits, 0, "");
        return combinations;
    }
};
