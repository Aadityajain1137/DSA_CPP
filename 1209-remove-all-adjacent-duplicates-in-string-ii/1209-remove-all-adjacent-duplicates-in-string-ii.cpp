class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string ans = "";
        for(auto x : s){
            if(!st.empty() && st.top().first == x){
                st.top().second++;
                if(st.top().second == k) st.pop();
            }else{
                st.push({x , 1});
            }
        }
        while(!st.empty()){
                int a = st.top().second;
                while(a--){
                    ans.push_back(st.top().first);
                }
                st.pop();
        }
        reverse(ans.begin() , ans.end());
            return ans;
    }
};