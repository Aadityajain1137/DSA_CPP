class Solution {
public:
    int ans = INT_MAX;
    vector<vector<vector<bool>>> vis;

    void solve(int i, int j, vector<vector<int>>& grid, int xr) {
        int m = grid.size();
        int n = grid[0].size();

        xr ^= grid[i][j];

        if (vis[i][j][xr]) return;
        vis[i][j][xr] = true;

        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xr);
            return;
        }

        if (i + 1 < m)
            solve(i + 1, j, grid, xr);

        if (j + 1 < n)
            solve(i, j + 1, grid, xr);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vis.assign(m, vector<vector<bool>>(
            n, vector<bool>(1024, false)
        ));

        ans = INT_MAX;
        solve(0, 0, grid, 0);

        return ans;
    }
};