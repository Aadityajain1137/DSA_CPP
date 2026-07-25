class Solution {
public:
    int maxProduct(int n) {
        vector<int> ans;
        while(n){
            int digit = n%10;
            ans.push_back(digit);
            n = n/10;
        }
        int first = INT_MIN;
        int second = INT_MIN;
        for(int x : ans){
            if(x > first){
                second = first;
                first = x;
            }
            else if(x > second){
                second = x;
            }
        }
        return first*second;
    }
};