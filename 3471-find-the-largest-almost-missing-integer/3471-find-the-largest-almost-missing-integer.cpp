class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int i =0;
        int j = k;
         int n = nums.size();
        unordered_set<int> s;
         unordered_map<int, int> mp;
        for(int x=0;x<j;x++){
            s.insert(nums[x]);
        }
        for (auto &x : s) {
            mp[x]++;
        }
        i++;
        j++;
        while(j<=n){
             s.clear();

            for (int x = i; x < j; x++) {
                s.insert(nums[x]);
            }

            for (auto &x : s) {
                mp[x]++;
            }

            i++;
            j++;
        }
        int ans = -1;
        for (auto &it : mp) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};