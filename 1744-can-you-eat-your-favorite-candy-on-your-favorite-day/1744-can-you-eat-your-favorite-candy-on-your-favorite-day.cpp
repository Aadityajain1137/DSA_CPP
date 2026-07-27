class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> prefix(n);
        prefix[0] = candiesCount[0];
        for(int i=1;i<n;i++){
            prefix[i] = candiesCount[i] + prefix[i-1];
        }
        vector<bool> ans;
        for(auto x : queries){
            int type = x[0];
            long long day = x[1];
            long long cap = x[2];
            long long start = type == 0 ? 1 : prefix[type-1]+1;
            long long end = prefix[type];
            long long minVal = day+1;
            long long maxVal = (day+1)* cap;
            if(maxVal>=start && minVal <= end){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};