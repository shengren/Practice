class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int pos = 0;
        int inc = 0;
        string sum = "";
        while (pos < a.length() && pos < b.length()) {
            int pos_sum = a[pos] - '0' + b[pos] - '0' + inc;
            sum += pos_sum % 2 + '0';
            inc = pos_sum / 2;
            ++pos;
        }
        while (pos < a.length()) {
            int pos_sum = a[pos] - '0' + inc;
            sum += pos_sum % 2 + '0';
            inc = pos_sum / 2;
            ++pos;
        }
        while (pos < b.length()) {
            int pos_sum = b[pos] - '0' + inc;
            sum += pos_sum % 2 + '0';
            inc = pos_sum / 2;
            ++pos;
        }
        if (inc == 1)
            sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
