struct Node {
  Node() : count(0) {
    for (int i = 0; i < 26; ++i)
      next[i] = nullptr;
  }

  int count;
  Node *next[26];
};

class WordDictionary {
 public:
  WordDictionary() : root(new Node()) {
  }

  // Adds a word into the data structure.
  void addWord(string word) {
    Node *c = root;
    for (int i = 0; i < word.size(); ++i) {
      int k = word[i] - 'a';
      if (c->next[k] == nullptr) c->next[k] = new Node();
      c = c->next[k];
    }
    ++c->count;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return searchFrom(word, 0, root);
  }

 private:
  Node *root;

  bool searchFrom(const string &word, int p, const Node *const c) {
    if (p == word.size()) return c->count > 0;
    if (word[p] != '.') {
      int k = word[p] - 'a';
      if (c->next[k] == nullptr) return false;
      return searchFrom(word, p + 1, c->next[k]);
    }
    for (int i = 0; i < 26; ++i)
      if (c->next[i] != nullptr &&
          searchFrom(word, p + 1, c->next[i]))
        return true;
    return false;
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
