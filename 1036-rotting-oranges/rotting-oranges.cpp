class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;
        if (q.empty())
            return -1;

        int ans = -1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (auto [a, b] : dirs) {
                    int i = x + a;
                    int j = y + b;

                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        fresh--;
                        q.push({i, j});
                    }
                }
            }

            ans++;
        }

        if (fresh == 0)
            return ans;

        return -1;
    }
};