class Solution {
public:
    bool isvalid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // 2D distance array initialized to INT_MAX
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        
        // Min-heap storing {effort, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > pq;

        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        res[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [dist, cell] = pq.top();
            auto [row, col] = cell;
            pq.pop();

            // Early exit optimization
            if (row == n - 1 && col == m - 1) return dist;

            if (dist > res[row][col]) continue;

            for (int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];

                if (!isvalid(r, c, n, m)) continue;

                // Path effort is max difference along the route
                int absdiff = abs(heights[row][col] - heights[r][c]);
                int newwt = max(absdiff, dist);

                if (newwt < res[r][c]) {
                    res[r][c] = newwt; // FIX: Update res array!
                    pq.push({newwt, {r, c}});
                }
            }
        }

        return res[n - 1][m - 1];
    }
};