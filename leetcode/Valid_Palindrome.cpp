#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.length() - 1;
        while (true) {
            while (front < s.length() && !isalnum(s[front]))  // alphanumeric
                ++front;
            while (back >= 0 && !isalnum(s[back]))
                --back;
            if (front >= back)
                break;
            if (tolower(s[front]) != tolower(s[back]))
                return false;
            ++front;  // forgot to shift front/back here at first
            --back;
        }
        return true;
    }
};
