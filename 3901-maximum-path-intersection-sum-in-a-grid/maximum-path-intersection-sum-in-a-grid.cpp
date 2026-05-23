class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = -101;
        int n = grid.size(), m = grid[0].size();

        for (int r = 0; r < n; r++) {
            int currMax = -101;
            int sum = grid[r][0];
            for (int c = 1; c < m; c++) {
                currMax = max(currMax, sum + grid[r][c]);
                sum = max(grid[r][c], sum + grid[r][c]);
            }
            ans = max(ans, currMax);
        }

        for (int c = 0; c < m; c++) {
            int currMax = -101;
            int sum = grid[0][c];
            for (int r = 1; r < n; r++) {
                currMax = max(currMax, sum + grid[r][c]);
                sum = max(grid[r][c], sum + grid[r][c]);
            }
            ans = max(ans, currMax);
        }

        for (int r = 1; r < n - 1; r++) {
            for (int c = 1; c < m - 1; c++) {
                ans = max(ans, grid[r][c]);
            }
        }

        return ans;
    }
};