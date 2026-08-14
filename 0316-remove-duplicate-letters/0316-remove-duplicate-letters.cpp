class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> used(26 , 0);
        unordered_map<char , int> mp;
        for(auto x : s){
            mp[x]++;
        }
        for(int i=0;i<s.length();i++){
            char curr = s[i];
            mp[curr]--;
            if(used[curr - 'a'] == 1) continue;
            while(!st.empty() && curr < st.top() && mp[st.top()]>0){
                used[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(curr);
            used[curr - 'a'] = 1;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};