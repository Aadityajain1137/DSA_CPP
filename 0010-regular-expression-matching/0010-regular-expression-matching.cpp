class Solution {
public:
    bool solve(int i , int j , string&s , string &p, vector<vector<int>>&dp){
        if(j == p.size()){
            return i == s.size();
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool ans;
        bool first = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if(j+1<p.length() && p[j+1] == '*'){
            ans = solve(i,j+2,s,p,dp) || (first && solve(i+1,j,s,p,dp));
        }
        else{
            ans = first && solve(i+1,j+1,s,p,dp);
        }
        dp[i][j] = ans;
        return ans;

    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m= p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solve(0,0, s , p,dp);
    }
};