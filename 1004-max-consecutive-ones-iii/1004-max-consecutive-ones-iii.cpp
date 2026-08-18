// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxLen = 0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int zero = 0;
//             for(int j = i;j<n;j++){
//                 if(nums[j]==0){
//                     zero++;
//                 }
//                 if(zero<=k){
//                     maxLen = max(maxLen,j-i+1);
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxLen;
//     }
// };
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int i = 0;
       int j = 0;
       int zero = 0;
       int n = nums.size();
       int maxLen = 0;
       while(j < n){
        if(nums[j] == 0){
            zero++;
        }
        if(zero>k){
            if(nums[i] == 0){
                zero--;
            }
            i++;
        }
        maxLen = max(maxLen , j - i +1);
        j++;
       } 
       return maxLen; 
    }
};