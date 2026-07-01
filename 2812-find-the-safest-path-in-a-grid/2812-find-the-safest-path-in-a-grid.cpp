class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        vector<vector<int>> safeness(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    safeness[i][j] = 0;
                }
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && safeness[nx][ny] == -1) {
                    safeness[nx][ny] = safeness[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        pq.push({safeness[0][0], {0, 0}});
        vis[0][0] = true;
        while (!pq.empty()) {
            auto [safe_val, coords] = pq.top();
            pq.pop();
            int x = coords.first;
            int y = coords.second;
            if (x == n - 1 && y == n - 1) {
                return safe_val;
            }  
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];  
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
                    int new_safe = min(safe_val, safeness[nx][ny]);
                    pq.push({new_safe, {nx, ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return 0;
    }
};