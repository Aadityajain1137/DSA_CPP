class Solution {
public:
    int n,m;

    long long helper(vector<vector<int>>& grid,int i,int j){
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(grid[i][j] == 0) return 0;
        long long curr = grid[i][j];
        grid[i][j] = 0;
        return curr + helper(grid,i-1,j) + helper(grid,i,j+1) + helper(grid,i+1,j) + helper(grid,i,j-1);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0){
                    if((helper(grid,i,j)) % k == 0) res++;
                }
            }
        }
        return res;
    }
};