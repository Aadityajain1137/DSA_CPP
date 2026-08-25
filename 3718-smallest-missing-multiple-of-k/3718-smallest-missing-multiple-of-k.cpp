class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto x : nums){
            st.insert(x);
        }
        for(int i=1;i<=102;i++){
            if(st.find(k * i) == st.end()){
                return k*i;
            }
        }
        return 0;
    }
};