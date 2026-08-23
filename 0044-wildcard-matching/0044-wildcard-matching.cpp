class Solution {
public:
    // bool solve(string s, string p, int i, int j,vector<vector<int>>&dp) {
    //     int n = s.length();
    //     int m = p.length();
    //     if (i == s.length()) {
    //         while (j < p.length()) {
    //             if (p[j] != '*')
    //                 return false;
    //             j++;
    //         }
    //         return true;
    //     }
    //     if (j == m)
    //         return false;
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i] == p[j] || p[j] == '?'){
    //         return dp[i][j] =  solve(s , p , i+1 , j+1,dp);
    //     }
    //     if(p[j] == '*'){
    //         return dp[i][j]= solve(s , p , i , j+1,dp) || solve(s , p , i+1 ,
    //         j,dp);
    //     }
    //     return dp[i][j] = false;
    // }
    bool isMatch(string s, string p) {
        // int n = s.length();
        // int m = p.length();

        // vector<vector<int>> dp(n , vector<int>(m , -1));
        //  return solve(s, p, 0, 0, dp);

        int n = s.length();
        int m = p.length();
        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*') {
                prev[j] = prev[j - 1];
            }
        }
        for(int i=1;i<=n;i++){
            curr[0] = false;
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[j-1] == '*'){
                    curr[j] =curr[j-1] || prev[j];
                }else{
                    curr[j] = false;
                }
            }
            prev = curr;
            fill(curr.begin(), curr.end(), false);
        }
        return prev[m];
    }
};