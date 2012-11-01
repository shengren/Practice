#include <iostream>
#include <string>
using namespace std;

class ColorfulChocolates {
public:
	int maximumSpread(string chocolates, int maxSwaps) {
	    int n = chocolates.size();
	    int lp[50];
	    int rp[50];
		int prec[26];
		for (int i = 0; i < 26; ++i) prec[i] = -1;
		for (int i = 0; i < n; ++i) lp[i] = rp[i] = -1;
		for (int i = 0; i < n; ++i) {
			int k = chocolates[i] - 'A';
			if (prec[k] != -1) {
				rp[prec[k]] = i;
				lp[i] = prec[k];
			}
			prec[k] = i;
		}
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			int aswap = maxSwaps;
			int l = i - 1;
			int r = i + 1;
			int lc = lp[i];
			int rc = rp[i];
			while (lc != -1 || rc != -1) {
				if (lc != -1 && rc != -1) {
					if (l - lc <= rc - r) {
						if (l - lc > aswap) break;
						aswap -= l - lc;
						--l;
						lc = lp[lc];
					} else {
						if (rc - r > aswap) break;
						aswap -= rc - r;
						++r;
						rc = rp[rc];
					}
					continue;
				}
				if (lc != -1) {
					if (l - lc > aswap) break;
					aswap -= l - lc;
					--l;
					lc = lp[lc];
					continue;
				}
				if (rc != -1) {
					if (rc - r > aswap) break;
					aswap -= rc - r;
					++r;
					rc = rp[rc];
				}
			}
			if (r - l - 1 > ret) ret = r - l - 1;
		}
		return ret;
	}
};