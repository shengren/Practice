class TrieNode {
 public:
  // Initialize your data structure here.
  TrieNode() {
    count = 0;
    for (int i = 0; i < 26; ++i)
      next[i] = nullptr;
  }

  int count;
  TrieNode *next[26];

};

class Trie {
 public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string s) {
    TrieNode *node = root;
    for (int i = 0; i < s.size(); ++i) {
      int k = s[i] - 'a';
      if (node->next[k] == nullptr)
        node->next[k] = new TrieNode();
      node = node->next[k];
    }
    ++node->count;
  }

  // Returns if the word is in the trie.
  bool search(string key) {
    TrieNode *node = root;
    for (int i = 0; i < key.size(); ++i) {
      int k = key[i] - 'a';
      if (node->next[k] == nullptr)
        return false;
      node = node->next[k];
    }
    return node->count > 0;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *node = root;
    for (int i = 0; i < prefix.size(); ++i) {
      int k = prefix[i] - 'a';
      if (node->next[k] == nullptr)
        return false;
      node = node->next[k];
    }
    return true;
  }

 private:
  TrieNode* root;

};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
