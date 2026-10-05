class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int ans = 0;
        for(auto x : s){
            if(x == '('){
                st.push(x);
            }
            else{
                if(st.size()>2){
                    ans+=st.size();
                }
                else{
                    ans++;
                    
                }
                st.pop();
            }
        }
        return ans;
    }
};