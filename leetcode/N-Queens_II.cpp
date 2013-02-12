class Solution {
    int num_distinct;
    bool board[12][12];  // n <= 12
    //set<long long> has;
    bool validate(int r, int c, int n) {
        for (int i = 0; i < r; ++i) {
            if (board[i][c])
                return false;
            if (c - (r - i) >= 0 && board[i][c - (r - i)])
                return false;
            if (c + (r - i) < n && board[i][c + (r - i)])
                return false;
        }
        return true;
    }
    /*long long convert1(int n) {
        long long config = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j])
                    config |= (j << (4 * i));
        return config;
    }
    long long convert2(int n) {
        long long config = 0;
        for (int j = n - 1; j >= 0; --j)
            for (int i = 0; i < n; ++i)
                if (board[i][j])
                    config |= (i << (4 * (n - 1 - j)));
        return config;
    }
    long long convert3(int n) {
        long long config = 0;
        for (int i = n - 1; i >= 0; --i)
            for (int j = n - 1; j >= 0; --j)
                if (board[i][j])
                    config |= ((n - 1 - j) << (4 * (n - 1 - i)));
        return config;
    }
    long long convert4(int n) {
        long long config = 0;
        for (int j = 0; j < n; ++j)
            for (int i = n - 1; i >= 0; --i)
                if (board[i][j])
                    config |= ((n - 1 - i) << (4 * j));
        return config;
    }*/
    void place(int k, int n) {
        if (k == n) {
            /*long long c1 = convert1(n, board);
            if (has.find(c1) != has.end())
                return;
            long long c2 = convert2(n, board);
            if (has.find(c2) != has.end())
                return;
            long long c3 = convert3(n, board);
            if (has.find(c3) != has.end())
                return;
            long long c4 = convert4(n, board);
            if (has.find(c4) != has.end())
                return;*/

            ++num_distinct;
            /*has.insert(c1);
            has.insert(c2);
            has.insert(c3);
            has.insert(c4);*/
            
            return;
        }
        for (int j = 0; j < n; ++j)
            if (validate(k, j, n)) {
                board[k][j] = true;
                place(k + 1, n);
                board[k][j] = false;
            }
    }
public:
    int totalNQueens(int n) {
        // Using vector leads to TLE.
        //vector<vector<bool> > board(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = false;
        num_distinct = 0;
        //has.clear();
        place(0, n);
        return num_distinct;
    }
};
