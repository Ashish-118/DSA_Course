class Solution
{
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        unordered_map<int, list<pair<int, int>>> adj;
        vector<int> indegree(V, 0);

        // Build graph
        for (auto &x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
            indegree[x[1]]++;
        }

        // Topological Sort using Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &nbr : adj[node])
            {
                int v = nbr.first;
                int wt = nbr.second;

                if (dist[node] != INT_MAX && dist[v] > dist[node] + wt)
                {
                    dist[v] = dist[node] + wt;
                }

                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Replace INT_MAX with -1 for unreachable nodes
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};
