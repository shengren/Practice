class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> after_addition(digits.size());
        int inc = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = digits[i] + inc;
            after_addition[i] = sum % 10;
            inc = sum / 10;
        }
        if (inc == 1) {
            after_addition[0] = 1;
            after_addition.push_back(0);
        }
        return after_addition;
    }
};
