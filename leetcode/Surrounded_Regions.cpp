// Use BFS. DFS causes Runtime Error.

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef pair<int, int> PII;

class Solution {
    int num_row;
    int num_col;
    void convert(vector<vector<char>> &board, char from, char to) {
        for (int i = 0; i < num_row; ++i)
            for (int j = 0; j < num_col; ++j)
                if (board[i][j] == from)
                    board[i][j] = to;
    }
    void floodfill(vector<vector<char>> &board, int r, int c) {
        board[r][c] = 'O';
        queue<PII> checking;
        checking.push(make_pair(r, c));
        while (!checking.empty()) {
            PII pii = checking.front();
            checking.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = pii.first  + dir[k][0];
                int nc = pii.second + dir[k][1];
                if (nr >= 0 && nr < num_row &&
                    nc >= 0 && nc < num_col &&
                    board[nr][nc] == '.') {
                    board[nr][nc] = 'O';
                    checking.push(make_pair(nr, nc));
                }
            }
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        num_row = board.size();
        if (num_row == 0) return;
        num_col = board[0].size();
        if (num_col == 0) return;
        convert(board, 'O', '.');
        for (int i = 0; i < num_row; ++i) {
            if (board[i][0] == '.')
                floodfill(board, i, 0);
            if (board[i][num_col - 1] == '.')
                floodfill(board, i, num_col - 1);
        }
        for (int j = 1; j < num_col - 1; ++j) {
            if (board[0][j] == '.')
                floodfill(board, 0, j);
            if (board[num_row - 1][j] == '.')
                floodfill(board, num_row - 1, j);
        }
        convert(board, '.', 'X');
    }
};
