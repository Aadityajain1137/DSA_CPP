class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : nums) {
            if(x > 0) {
                pq.push(x);
            }
        }

        int ans = 1;

        while(!pq.empty()) {

            int top = pq.top();
            pq.pop();

            if(top < ans) {
                continue;
            }

            if(top == ans) {
                ans++;
            }
            else {
                break;
            }
        }

        return ans;
    }
};