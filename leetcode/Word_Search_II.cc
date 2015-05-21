struct TrieNode {
  TrieNode *parent;
  TrieNode *child[26];
  int num_word_end;
  int num_word_below;

  TrieNode(TrieNode *par) : parent(par), num_word_end(0), num_word_below(0) {
    for (int i = 0; i < 26; ++i)
      child[i] = nullptr;
  }
};

int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    root = new TrieNode(nullptr);

    for (const string &word : words)
      AddWord(word);

    num_row = board.size();
    num_col = board[0].size();

    vector<vector<bool>> used(num_row, vector<bool>(num_col, false));

    vector<string> ret;

    for (int i = 0; i < num_row; ++i)
      for (int j = 0; j < num_col; ++j)
        Search(board, used, i, j, "", root, ret);

    return ret;
  }

 private:
  TrieNode *root;
  int num_row;
  int num_col;

  void AddWord(const string &word) {
    TrieNode *c = root;
    for (int i = 0; i < word.size(); ++i) {
      ++c->num_word_below;
      int k = word[i] - 'a';
      if (c->child[k] == nullptr) c->child[k] = new TrieNode(c);
      c = c->child[k];
    }
    ++c->num_word_end;
    if (c->num_word_end > 1) DeleteWord(c);  // Remove duplicates
  }

  void DeleteWord(TrieNode *c) {
    --c->num_word_end;
    while (true) {
      c = c->parent;
      if (c == nullptr) break;
      --c->num_word_below;
    }
  }

  void Search(const vector<vector<char>> &board, vector<vector<bool>> &used,
              int x, int y, string s, TrieNode *c, vector<string> &ret) {
    int k = board[x][y] - 'a';
    if (c->child[k] != nullptr)
      c = c->child[k];
    else
      return;
    s += board[x][y];
    
    if (c->num_word_end) {
      ret.push_back(s);
      DeleteWord(c);
    }

    if (c->num_word_below == 0) return;

    used[x][y] = true;
    for (int d = 0; d < 4; ++d) {
      int nx = x + dir[d][0];
      int ny = y + dir[d][1];
      if (nx >= 0 && nx < num_row && ny >= 0 && ny < num_col && !used[nx][ny])
        Search(board, used, nx, ny, s, c, ret);
    }
    used[x][y] = false;
  }

  // Does not delete the tree in the end; Memory leak
};
