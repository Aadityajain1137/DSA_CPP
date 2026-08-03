class Solution {
public:
    int solve(int i, vector<int>&stoneValue , vector<int>&dp){
        int n = stoneValue.size();
        if(i>=n) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int ans = INT_MIN;
        int sum = 0;
        for(int j=0;j<3 && i+j<n; j++){
            sum+=stoneValue[i+j];
            ans = max(ans , sum - solve(i + j + 1, stoneValue , dp));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n , INT_MIN);
        int ans = solve(0 , stoneValue , dp);
        if(ans > 0) return "Alice";
        else if (ans<0) return "Bob";
        return "Tie";
    }
};