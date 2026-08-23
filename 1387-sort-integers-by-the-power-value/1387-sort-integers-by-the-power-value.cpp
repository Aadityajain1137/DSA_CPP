class Solution {
public:
    unordered_map<int, int> dp;
    int solve(int i) {
        if (i == 1)
            return 0;
        if (dp.count(i))
            return dp[i];
        if (i % 2 == 0) {
            return dp[i] = 1 + solve(i / 2);
        } else {
            return dp[i] = 1 +solve(3 * i + 1);
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> ans;
        for (int i = lo; i <= hi; i++) {
            
            ans.push_back({solve(i), i});
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1].second;
    }
};