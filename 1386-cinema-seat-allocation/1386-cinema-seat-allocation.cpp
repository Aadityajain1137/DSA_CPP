class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        unordered_map<int,vector<int>> mp;
        for(auto x : a){
            mp[x[0]].push_back(x[1]);
        }
        int ans = (n - mp.size())*2;
        for(auto x : mp){
            int row = x.first;
            bool left = true;
            bool right = true;
            bool middle = true;
            for(int x : x.second){
                if(x>=2 && x<=5) left = false;
                if(x>=4 && x<=7) middle = false;
                if(x>=6 && x<=9) right = false;
            }
            if(left && right) ans+=2;
            else if(left || right || middle) ans+=1;
        }
        return ans;
    }
};