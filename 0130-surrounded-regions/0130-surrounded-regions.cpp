class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }

    void dfs(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        board[r][c] = '#';
        for (int k = 0; k < 4; k++) {
            int nrow = r + x[k];
            int ncol = c + y[k];
            if (valid(board, nrow, ncol, rows, cols) && board[nrow][ncol] == 'O') {
                dfs(board, nrow, ncol, rows, cols);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // 1. Traverse top and bottom boundaries (across all columns)
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c, rows, cols);
            }
            if (board[rows - 1][c] == 'O') {
                dfs(board, rows - 1, c, rows, cols);
            }
        }
        
        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0, rows, cols);
            }
            if (board[r][cols - 1] == 'O') {
                dfs(board, r, cols - 1, rows, cols);
            }
        }


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};