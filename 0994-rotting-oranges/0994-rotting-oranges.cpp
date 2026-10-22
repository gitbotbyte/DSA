class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool isvalid(int r, int c, int rows, int cols) {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshcount = 0;
        int tt = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                    grid[r][c] = 0;
                } else if (grid[r][c] == 1) {
                    freshcount++;
                }
            }
        }
        while (!q.empty() && freshcount > 0) {
            tt++;
            int s = q.size();
            while (s--) {
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                for (int k = 0; k < 4; k++) {
                    int nrow = r + x[k];
                    int ncol = c + y[k];
                    if (isvalid(nrow, ncol, rows, cols) &&
                        grid[nrow][ncol] == 1) {
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = 0;
                        freshcount--;
                    }
                }
            }
        }
        if (freshcount > 0)
            return -1;
        return tt;
    }
};