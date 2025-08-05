class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> dist(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);
        for (auto &f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }
        queue<pair<int, int>> q;
        dist[src] = 0;
        q.push({0, src});
        int steps = 0;
        while (!q.empty() && steps <= k)
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                auto [cost, node] = q.front();
                q.pop();
                if (node == dst)
                    continue;
                for (auto iter : adj[node])
                {
                    int v = iter.first, w = iter.second;
                    if (dist[v] > cost + w)
                    {
                        dist[v] = cost + w;
                        q.push({dist[v], v});
                    }
                }
            }

            steps++;
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};