class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> st(nums.begin(), nums.end());
        // int longest = 0;
        // int current = 0;
        // for (int num : st) {
        //     if (!st.count(num - 1)) {
        //         int current = num;
        //         int longe = 1;
        //         while (st.count(current + 1)) {
        //             current++;
        //             longe++;
        //         }

        //         longest = max(longest, longe);
        //     }
        // }
        // return longest;
         if(nums.empty()) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x : nums){
            pq.push(x);
        }
        int ans = 1;
        int maxi = 1;
        int prev = pq.top();
        pq.pop();
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            if(top == prev) {
                continue;
            }
            if(top == prev+1){
                ans++;
            }
            else{
                ans = 1;
            }
            prev = top;
            maxi = max(ans , maxi);
        }
        return maxi;
    }
};