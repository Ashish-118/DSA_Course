class Solution
{
public:
    using p = pair<int, int>;
    int minCost(int n, vector<vector<int>> &edges)
    {

        vector<int> dist(n, INT_MAX);

        priority_queue<p, vector<p>, greater<p>> pq;

        unordered_map<int, list<p>> adj;

        for (auto e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int node = top.second, w = top.first;

            if (dist[node] < w)
                continue; // stale entry

            if (node == n - 1)
            {
                return w;
            }

            for (auto &ngb : adj[node])
            {
                if (dist[ngb.first] > w + ngb.second)
                {
                    dist[ngb.first] = w + ngb.second;
                    pq.push({dist[ngb.first], ngb.first});
                }
            }
        }

        return -1;
    }
};