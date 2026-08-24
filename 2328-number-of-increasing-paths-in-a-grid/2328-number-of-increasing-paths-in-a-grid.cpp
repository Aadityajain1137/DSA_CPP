class Solution {
public:
    int MOD = 1e9+7;
    int solve(int r, int c, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (r >= n || c >= m)
            return 0;
        if (dp[r][c] != -1)
            return dp[r][c];
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int ni = r + drow[i];
            int nj = c + dcol[i];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                grid[ni][nj] > grid[r][c]) {
               ans = (ans + solve(ni, nj, grid, dp)) % MOD;
            }
        }
        dp[r][c] = ans;
        return ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               ans = (ans + solve(i, j, grid, dp)) % MOD;
            }
        }
        return ans;
    }
};