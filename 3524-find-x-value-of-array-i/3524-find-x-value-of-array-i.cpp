class Solution {
public:
    int n, k;
    vector<int> nums;
    vector<vector<vector<long long>>> memo;
    vector<vector<bool>> vis;

    vector<long long> solve(int i, int rem) {
        if (i == n)
            return vector<long long>(k, 0);

        if (vis[i][rem])
            return memo[i][rem];

        vis[i][rem] = true;

        vector<long long> res(k, 0);

        int newRem = (1LL * rem * nums[i]) % k;

        res[newRem]++;

        vector<long long> next = solve(i + 1, newRem);

        for (int r = 0; r < k; r++) {
            res[r] += next[r];
        }

        return memo[i][rem] = res;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        this->nums = nums;
        this->n = nums.size();
        this->k = k;

        memo.resize(n, vector<vector<long long>>(k));
        vis.assign(n, vector<bool>(k, false));

        vector<long long> ans(k, 0);

        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;

            ans[rem]++;

            if (i + 1 < n) {
                vector<long long> temp = solve(i + 1, rem);

                for (int r = 0; r < k; r++)
                    ans[r] += temp[r];
            }
        }

        return ans;
    }
};