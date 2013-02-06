class Solution {
    vector<string> combinations;
    void generate(string s, int num_left, int num_pair) {
        if (s.length() == 2 * num_pair) {
            if (num_left == 0)
                combinations.push_back(s);
            return;
        }
        if (num_left > 0)
            generate(s + ")", num_left - 1, num_pair);
        generate(s + "(", num_left + 1, num_pair);
    }
public:
    vector<string> generateParenthesis(int n) {
        combinations.clear();
        generate("(", 1, n);
        return combinations;
    }
};
