class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    // Corrected parameter naming: n = rows, m = cols
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }

    void dfs(vector<vector<char>>& a, int n, int m, int i, int j, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            
            // Pass n (rows) and m (cols) in consistent order
            if (valid(row, col, n, m) && a[row][col] == '1' && !vis[row][col]) {
                dfs(a, n, m, row, col, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& a) {
        if (a.empty() || a[0].empty()) return 0;

        int n = a.size();       // Number of rows
        int m = a[0].size();    // Number of columns
        int res = 0;

        // Fix 1: Properly size 2D vis array to n rows x m cols
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Fix 2: Outer loop traverses rows (0 to n-1), inner loop traverses cols (0 to m-1)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1' && !vis[i][j]) {
                    dfs(a, n, m, i, j, vis);
                    res++;
                }
            }
        }
        return res;
    }
};