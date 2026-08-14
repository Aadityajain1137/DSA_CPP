class Solution {
public:
    vector<pair<int,int>> getPairs(string s){
        vector<pair<int,int>> v;
        for(int i=0;i<s.length(); ){
            int digit = s[i] - '0';
            int count = 0;
            while(i<s.length() && s[i]-'0' == digit){
                count++;
                i++;
            }
            v.push_back({digit , count});
        }
        return v;
    }
    string makeAns(vector<pair<int,int>> &v){
        string ans;
        for(auto it : v){
            int digit = it.first;
            int count = it.second;
            ans += to_string(count);
            ans += to_string(digit);
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1;i<n;i++){
            vector<pair<int,int>> pairs = getPairs(ans);
            ans =  makeAns(pairs);
        }
        return ans;
        
    }
};