class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>left(n , 0);
        vector<int> right(n , 0);
        int miniPrice = INT_MAX;
        for(int i=0;i<n;i++){
            miniPrice = min(miniPrice ,prices[i]);
            int profit = prices[i] - miniPrice;
            if(i>0){
                left[i] = max(left[i-1] , profit);
            }
            else{
                left[i] = profit;
            }
        }
        int maxiPrice = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxiPrice = max(maxiPrice , prices[i]);
            int profit = maxiPrice - prices[i];
            if(i<n-1){
                 right[i] = max(right[i + 1], profit);
            }else right[i] = profit;
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};