class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int count =0;
        for(int x : s){
            if(x == '('){
                st.push('(');
                count = max((int)st.size() , count);
            } 
            else if(x == ')') st.pop();
        }
        return count;
    }
};