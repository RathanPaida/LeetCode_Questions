class Solution {
private:
    bool dfs(int r, int c, int open, const vector<vector<char>>& grid,
             vector<vector<vector<int>>>& memo) {
        int m = grid.size(), n = grid[0].size();
        open += grid[r][c] == '(' ? 1 : -1;

        if (open < 0 || open > m + n - 2 - r - c)
            return false;
        if (r == m - 1 && c == n - 1)
            return open == 0;
        if (memo[r][c][open] != -1)
            return memo[r][c][open];

        return memo[r][c][open] =
                   (r + 1 < m && dfs(r + 1, c, open, grid, memo)) ||
                   (c + 1 < n && dfs(r, c + 1, open, grid, memo));
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), len = m + n - 1;

        if (len % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(len + 1, -1)));

        return dfs(0, 0, 0, grid, memo);
    }
};