#include <iostream>
#include <string>
#include <map>
using namespace std;

class EllysCheckers {
public:
	map<string, bool> cache;
	bool search(string s) {
		if (cache.find(s) != cache.end()) return cache[s];
		for (int i = 0; i < s.size() - 1; ++i)
			if (s[i] == 'o') {
				if (s[i + 1] == '.') {
					string ns = s;
					ns[i] = '.';
					if (i + 1 != s.size() - 1) ns[i + 1] = 'o';
					if (!search(ns)) return (cache[s] = true);
				}
				if (i < s.size() - 3 && s[i + 1] == 'o' && s[i + 2] == 'o' && s[i + 3] == '.') {
					string ns = s;
					ns[i] = '.';
					if (i + 3 != s.size() - 1) ns[i + 3] = 'o';
					if (!search(ns)) return (cache[s] = true);
				}
			}
		return (cache[s] = false);
	}
	string getWinner(string board) {
		cache.clear();
		if (board[board.size() - 1] == 'o') board[board.size() - 1] = '.';
		return search(board) ? "YES" : "NO";
	}
};
