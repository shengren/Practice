class Solution {
public:
    int romanToInt(string s) {
        int x = 0;
        for (int i = 0; i < s.length();) {
            if (i + 1 < s.length()) {
                string u = s.substr(i, 2);
                bool flag = false;
                if (u == "CM") {
                    x += 900;
                    flag = true;
                } else if (u == "CD") {
                    x += 400;
                    flag = true;
                } else if (u == "XC") {
                    x += 90;
                    flag = true;
                } else if (u == "XL") {
                    x += 40;
                    flag = true;
                } else if (u == "IX") {
                    x += 9;
                    flag = true;
                } else if (u == "IV") {
                    x += 4;
                    flag = true;
                }
                if (flag) {
                    i += 2;
                    continue;  // Cannot skip the third part in for-loop
                }
            }
            string u = s.substr(i, 1);
            if (u == "M")
                x += 1000;
            else if (u == "D")
                x += 500;
            else if (u == "C")
                x += 100;
            else if (u == "L")
                x += 50;
            else if (u == "X")
                x += 10;
            else if (u == "V")
                x += 5;
            else if (u == "I")
                x += 1;
            ++i;
        }
        return x;
    }
};
