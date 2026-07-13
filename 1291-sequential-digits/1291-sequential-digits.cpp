class Solution {
public:
    void solve(int i ,int last,  int low , int high , vector<int>& ans){
        if(i>high) return;
        if(i>=low) ans.push_back(i);
        if(last == 9) return;
        solve(i*10+(last+1) , last+1 , low , high , ans);
    }
    vector<int> sequentialDigits(int low, int high) {
         vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(i , i , low , high, ans);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};