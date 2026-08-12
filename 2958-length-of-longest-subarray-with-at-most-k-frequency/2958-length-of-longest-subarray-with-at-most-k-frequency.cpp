class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int i =0;
        int j = 0;
        int maxLen = INT_MIN;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            int len = j - i +1;
            maxLen = max(maxLen , len);
            j++;
        }
        return maxLen;
    }
};