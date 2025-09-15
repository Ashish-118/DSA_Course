class Solution
{
public:
    int dfs(int node, vector<bool> &visited, unordered_map<int, list<pair<int, int>>> &adj)
    {
        visited[node] = true;
        int mini = INT_MAX;

        for (auto &x : adj[node])
        {
            mini = min(mini, x.second);
            if (!visited[x.first])
            {
                mini = min(mini, dfs(x.first, visited, adj));
            }
        }

        return mini;
    }

    int minScore(int n, vector<vector<int>> &roads)
    {

        vector<bool> visited(n, false);
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto &x : roads)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }

        return dfs(1, visited, adj);
    }
};

/// advanced code

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto r : roads)
            graph[r[0]][r[1]] = graph[r[1]][r[0]] = r[2];

        unordered_set<int> vis;

        function<int(int)> dfs;
        dfs = [&](int n) -> int
        {
            int res = INT_MAX;
            vis.insert(n);

            for (auto [adj, scr] : graph[n])
            {
                if (!vis.count(adj))
                    res = min(res, dfs(adj));
                res = min(res, scr);
            }

            return res;
        };

        return dfs(1);
    }
};