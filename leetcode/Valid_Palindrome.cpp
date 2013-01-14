#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (true) {
            while (left < s.length() && !isalnum(s[left]))  // alphanumeric
                ++left;
            while (right >= 0 && !isalnum(s[right]))
                --right;
            if (left >= right)
                break;
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            ++left;  // forgot to shift left/right here at first
            --right;
        }
        return true;
    }
};
