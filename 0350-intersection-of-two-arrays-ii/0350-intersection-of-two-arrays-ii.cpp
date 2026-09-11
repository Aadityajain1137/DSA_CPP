class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int x : nums1){
            mp[x]++;
        }
        for(int x : nums2){
            if(mp[x]>0){
                ans.push_back(x);
                mp[x]--;
            }
        }
        return ans;
    }
};