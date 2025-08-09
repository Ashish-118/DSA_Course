class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& sub) {
        visited[node] = true;
        sub.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, sub);
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        vector<vector<int>> ans;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                vector<int> sub;
                dfs(i, adj, visited, sub);
                ans.push_back(sub);
            }
        }

        return ans;
    }
};
