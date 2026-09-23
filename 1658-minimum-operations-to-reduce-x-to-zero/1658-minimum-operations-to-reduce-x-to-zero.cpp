class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left =0 , right = 0;
        int total = 0;
        for(auto a : nums){
            total+=a;
        }
        if(total<x) return -1;
        long long target = total - x;
        long long sum = 0;
        if(total == 0) return nums.size();
        int n = nums.size();
        int maxLen = -1;
        while(right<n){
            sum+=nums[right];
            while(sum>target && left <= right){
                sum-=nums[left];
                left++;
            }
            if(sum == target) maxLen = max(maxLen , right - left + 1);
            right++;
        }
        return maxLen == -1 ? -1 : n - maxLen;
    }
};