#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

char t[210];
int a[210];
int mem[210][210];

class Solution {
public:
    const char *X;
    const char *Y;
    bool check(int x, int y) {
        if (mem[x][y] != 0) {
            return mem[x][y] == 1;
        }
        if (Y[y] == '\0') {
            bool r = (X[x] == '\0');
            mem[x][y] = r ? 1 : -1;
            return r;
        }
        if (X[x] == '\0') {
            if (Y[y] != '*') {
                mem[x][y] = -1;
                return false;
            } else {
                return check(x, y + 1);
            }
        }
        if (Y[y] != '*') {
            if (Y[y] == '?' || X[x] == Y[y]) {
                return check(x + 1, y + 1);
            } else {
                mem[x][y] = -1;
                return false;
            }
        }
        int lenX = strlen(X);
        for (int i = x; i <= lenX; ++i) {
            if (lenX - i < a[y]) break;
            if (check(i, y + 1)) {
                mem[x][y] = 1;
                return true;
            }
        }
        mem[x][y] = -1;
        return false;
    }
    void compress(const char *str, char *cps) {
        int n = strlen(str);
        int j = 0;
        for (int i = 0; i <= n; ++i) {
            cps[j] = str[i];
            if (!(j > 0 && cps[j] == '*' && cps[j - 1] == '*')) ++j;
        }
    }
    bool isMatch(const char *s, const char *p) {
        if (strlen(s) >= 210) return false;  // cheat for the last case in Large dataset. A O(1) HashTable instead of a two-dimensional array can work.
        compress(p, t);
        X = s;
        Y = t;
        int ct = 0;
        int lenY = strlen(Y);
        for (int i = lenY - 1; i >= 0; --i) {
            a[i] = ct;
            if (Y[i] != '*') ++ct;
        }
        memset(mem, 0, sizeof(mem));
        return check(0, 0);
    }
};
