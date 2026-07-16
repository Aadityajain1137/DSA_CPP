class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxi = max(nums[i], maxi);
            prefix[i] = gcd(nums[i], maxi);
        }
        long long ans = 0;
        int x = 0;
        int y = n - 1;
        sort(prefix.begin() , prefix.end());
        while (x < y) {
            ans += gcd(prefix[x], prefix[y]);
            x++;
            y--;
        }
        return ans;
    }
};