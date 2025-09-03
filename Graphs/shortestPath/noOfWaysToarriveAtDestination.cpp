#define mod 1000000007
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (auto &r : roads)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // Dijkstra setup
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        // min-heap: {distance, node}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) // this is to handle the duplicates which we don't delete when we changed the distance of a node
                continue;    // stale entry

            for (auto &[v, wt] : adj[u])
            {
                long long newDist = d + wt;

                if (newDist < dist[v])
                {
                    dist[v] = newDist;
                    ways[v] = ways[u]; // new shortest path found
                    pq.push({newDist, v});
                }
                else if (newDist == dist[v])
                {
                    // another shortest path found
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
