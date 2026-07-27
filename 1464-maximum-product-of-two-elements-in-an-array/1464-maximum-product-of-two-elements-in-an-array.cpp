class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN , second = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>first){
                second = first;
                first = nums[i];
            }
            else if(nums[i]>second){
                second = nums[i];
            }
        }
        first--;
        second--;
        return first * second;
    }
};