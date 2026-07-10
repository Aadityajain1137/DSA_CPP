class Solution {
public:
    void solve(int i , unordered_map<int,vector<int>>& adj, vector<int>&visited , vector<int>&color){
        visited[i] = 1;
        bool used[5] = {false};
        for(auto nei : adj[i]){
            if(color[nei]!=0){
                used[color[nei]] = true;
            }
        }
        for(int c = 1;c<=4;c++){
            if(!used[c]){
                color[i] = c;
                break;
            }
        }
        for(auto nei : adj[i]){
            if(!visited[nei]){
                solve(nei , adj , visited , color);
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int,vector<int>> adj;
        for(auto x : paths){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n+1, 0);
        vector<int> color(n +1, 0);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                solve(i , adj , visited , color );
            }
        }
        return vector<int>(color.begin() + 1, color.end());
    }
};