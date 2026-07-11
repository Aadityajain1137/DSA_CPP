class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, vector<int>& visited, int i,
             vector<int>& component) {
        visited[i] = 1;
        component.push_back(i);
        for (auto nei : adj[i]) {
            if (!visited[nei]) {
                dfs(adj, visited, nei, component);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;

                dfs(adj, visited, i, component);

                int nodes = component.size();

                int edge = 0;

                for (int node : component)
                    edge += adj[node].size();

                edge /= 2;

                if (edge == nodes * (nodes - 1) / 2)
                    count++;
            }
        }
        return count;
    }
};