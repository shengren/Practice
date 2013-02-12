class Solution {
    string multiply(string a, int b, int num_ending_zeros) {
        string c = "";
        for (int i = 0; i < num_ending_zeros; ++i)
            c += '0';
        int inc = 0;
        for (int i = 0; i < a.length(); ++i) {
            int sum = inc + (a[i] - '0') * b;
            c += sum % 10 + '0';
            inc = sum / 10;
        }
        if (inc > 0)
            c += inc + '0';
        return c;
    }
    string add(string a, string b) {
        string c = "";
        int i = 0;
        int inc = 0;
        while (i < a.length() && i < b.length()) {
            int sum = inc + a[i] - '0' + b[i] - '0';
            c += sum % 10 + '0';
            inc = sum / 10;
            ++i;
        }
        while (i < a.length()) {
            int sum = inc + a[i] - '0';
            c += sum % 10 + '0';
            inc = sum / 10;
            ++i;
        }
        while (i < b.length()) {
            int sum = inc + b[i] - '0';
            c += sum % 10 + '0';
            inc = sum / 10;
            ++i;
        }
        if (inc > 0)
            c += inc + '0';
        return c;
    }
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string product;
        for (int i = 0; i < num2.length(); ++i)
            if (i == 0)
                product = multiply(num1, num2[i] - '0', i);
            else
                product = add(product,
                              multiply(num1, num2[i] - '0', i));
        reverse(product.begin(), product.end());
        return product;
    }
};
