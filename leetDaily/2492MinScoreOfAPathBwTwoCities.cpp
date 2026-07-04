class Solution {
public:
    vector<bool> visited;
    unordered_map<int, list<pair<int, int>>> adj;
    int dfs(int node) {
        visited[node] = true;

        int mini = INT_MAX;

        for (auto ngb : adj[node]) {
            mini = min(mini, ngb.second);
            if (!visited[ngb.first]) {
                mini = min(mini, dfs(ngb.first));
            }
        }

        return mini;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        for (auto r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        visited.assign(n + 1, false);

        return dfs(1);
    }
};