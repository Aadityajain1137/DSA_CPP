class Solution {
public:
    int reverseDegree(string s) {
        int i = 1;
        int ans = 0;
        for(auto x : s){
            int num = 'z' - x+1;
            int to = i*num;
            ans+=to;
            i++;
        }
        return ans;
    }
};