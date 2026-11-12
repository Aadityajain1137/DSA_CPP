class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int sinc = 1;
        int sdec = 1;
        int ans = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                sinc++;
                sdec = 1;
            }
            else if(nums[i] < nums[i-1]) {
                sdec++;
                sinc = 1;
            }
            else {
                sinc = 1;
                sdec = 1;
            }

            ans = max(ans, max(sinc, sdec));
        }

        return ans;
    }
};