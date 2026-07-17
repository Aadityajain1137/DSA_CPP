class Solution {
public:
    // int solve(vector<vector<int>> &grid , int i , int j){
    //     int r = grid.size();
    //     int c = grid[0].size();
    //     if(i==r-1 && j==c-1){
    //         return grid[i][j];
    //     }
    //     int right = INT_MAX;
    //     int down = INT_MAX;
    //     if(j+1<c){
    //         right = grid[i][j]+solve(grid,i,j+1);
    //     }
    //     if(i+1<r){
    //         down = grid[i][j]+solve(grid,i+1,j);
    //     }
    //     return min(right,down);
    // }

    int solve1(vector<vector<int>> &grid , int i , int j,vector<vector<int>> &dp){
        int r = grid.size();
        int c = grid[0].size();
        if(i==r-1 && j==c-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = INT_MAX;
        int down = INT_MAX;
        if(j+1<c){
            right = grid[i][j]+solve1(grid,i,j+1,dp);
        }
        if(i+1<r){
            down = grid[i][j]+solve1(grid,i+1,j,dp);
        }
        return dp[i][j] =  min(right,down);
    }

    int solve(vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n , vector<int>(m , 0));
        dp[0][0] =grid[0][0];
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int right = dp[i-1][j] + grid[i][j];
                int down = dp[i][j-1] + grid[i][j];
                dp[i][j] = min(right , down);
            }
        }
        return dp[n-1][m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int r = grid.size();
        // int c = grid[0].size();
        // vector<vector<int>> dp(r,vector<int>(c,-1));
        // return solve1(grid,0,0,dp);
        return solve(grid);
    }
};