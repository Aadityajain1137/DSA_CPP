class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : nums) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }

        vector<int> ans;
        for (int x : arr) {
            ans.push_back(rank[x]);
        }

        return ans;
    }
};