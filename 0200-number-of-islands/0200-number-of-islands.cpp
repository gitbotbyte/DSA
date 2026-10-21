class Solution {
public:

    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};


    bool isValid(int r, int c, int rows, int cols) {
        return (r >= 0 && r < rows && c >= 0 && c < cols);
    }

    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& vis) {
        int rows = grid.size();
        int cols = grid[0].size();

        vis[r][c] = true;


        for (int k = 0; k < 4; k++) {
            int newRow = r + x[k];
            int newCol = c + y[k];

            if (isValid(newRow, newCol, rows, cols) && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                dfs(grid, newRow, newCol, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));


        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && !vis[r][c]) {
                    dfs(grid, r, c, vis);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};