#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StrIIRec {
public:
	string ret;
	bool dfs(const int n, const int minInv, const string minStr, vector<bool> &used, string s, int inv) {
		int k = s.size();
		if (k == n) {
			ret = s;
			return true;
		}
		int less = 0;
		for (int i = 0; i < n; ++i)
			if (!used[i]) {
				if (s + (char)('a' + i) >= minStr.substr(0, k + 1)) {
					if (inv + less + (n - k - 2) * (n - k - 1) / 2 >= minInv) {
						used[i] = true;
						bool r = dfs(n, minInv, minStr, used, s + (char)('a' + i), inv + less);
						if (r) return true;
						used[i] = false;
					}
				}
				++less;
			}
		return false;
	}
	string recovstr(int n, int minInv, string minStr) {
		ret = "";
		vector<bool> used(n);
		for (int i = 0; i < n; ++i) used[i] = false;
		dfs(n, minInv, minStr, used, "", 0);
		return ret;
	}
};
