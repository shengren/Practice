#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

char s[100001];
int ns;
char cs[100001];
int ct[100001];
int ncs;

int main(void) {
  int ncase;
  scanf("%d", &ncase);
  while (ncase--) {
    scanf("%s", s);
    ns = strlen(s);
    
    ncs = 0;
    cs[0] = s[0];
    ct[0] = 1;
    for (int i = 1; i < ns; ++i) {
      if (s[i] == cs[ncs]) {
        ct[ncs]++;
      } else {
        ++ncs;
        cs[ncs] = s[i];
        ct[ncs] = 1;
      }
    }
    ++ncs;

    int res = ns + (ct[0] - 1) * ct[0] / 2;
    for (int i = 1; i < ncs; ++i) {
      for (int j = ct[i]; j >= 1; --j) {
        int p = 0;
        int q = i;
        int qt = j;
        int w = 0;
        while (q < ncs) {
          if (cs[p] == cs[q]) {
            if (ct[p] == qt) {
              w += ct[p];
              p++;
              q++;
              qt = ct[q];
            } else {
              w += min(ct[p], qt);
              break;
            }
          } else {
            break;
          }
        }
        res += w;
      }
    }
    printf("%d\n", res);
  }

  return 0;
}
