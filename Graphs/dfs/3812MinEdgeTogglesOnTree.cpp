class Solution
{
public:
    vector<vector<pair<int, int>>> adj;
    vector<int> res, diff;
    void dfs(int u, int p)
    {
        for (auto [v, idx] : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u); // bottom up
            if (diff[v])
            {
                res.push_back(idx);
                diff[v] ^= 1; // 0->1, 1->0
                diff[u] ^= 1;
            }
        }
    }
    vector<int> minimumFlips(int n, vector<vector<int>> &edges, string start,
                             string target)
    {
        adj.assign(n, {});
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        diff.resize(n);
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if (start[i] != target[i])
                diff[i] = 1, s++;
        }
        if (s & 1)
            return {-1};
        dfs(0, -1);
        // after dfs both start[i] must become target[i]
        for (int i = 0; i < n; i++)
        {
            if (diff[i])
                return {-1};
        }
        sort(res.begin(), res.end());
        return res;
    }
};