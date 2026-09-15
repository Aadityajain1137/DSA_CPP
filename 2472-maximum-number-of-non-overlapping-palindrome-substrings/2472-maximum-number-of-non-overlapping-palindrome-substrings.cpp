// class Solution {
// public:
//     bool isPalindrome(string &s , int i, int j){
//         while(i<=j){
//             if(s[i]!=s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     int solve(string &s , int i , int k , vector<int>&dp){
//         int n = s.length();
//         if(i>=n) return 0;
//         if(dp[i]!=-1) return dp[i];
//         int ans = solve(s , i+1 , k , dp);
//         for(int j = i+k-1;j<n;j++){
//             if(isPalindrome(s , i , j)){
//                 ans = max(ans , 1 + solve(s , j+1,k, dp));
//             }
//         }
//         return dp[i] = ans;
//     }
//     int maxPalindromes(string s, int k) {
//         int n = s.length();
//         vector<int> dp(n , -1);
//         return solve(s , 0 , k , dp);
//     }
// };

class Solution {
public:
    int solve(string& s, int i, int k, vector<int>& dp,
              vector<vector<bool>>& pal) {

        int n = s.size();

        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];
        int ans = solve(s, i + 1, k, dp, pal);
        for (int j = i + k - 1; j < n; j++) {
            if (pal[i][j]) {
                ans = max(ans, 1 + solve(s, j + 1, k, dp, pal));
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }
        for (int len = 2; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {

                    if (len == 2)
                        pal[i][j] = true;

                    else
                        pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }

        vector<int> dp(n, -1);

        return solve(s, 0, k, dp, pal);
    }
};