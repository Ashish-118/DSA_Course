class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        unordered_map<int, list<int>> graph;
        int v = adj.size();

        for (int i = 0; i < v; i++)
        {
            for (auto &x : adj[i])
            {
                graph[i].push_back(x);
            }
        }

        vector<bool> visited(v, false);

        vector<int> value(v, -1);
        vector<int> parent(v, -1);

        queue<int> q;
        q.push(src);
        value[src] = 0;
        visited[src] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            if (parent[front] != -1)
            {
                value[front] = value[parent[front]] + 1;
            }

            for (auto &x : adj[front])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                    parent[x] = front;
                }
            }
        }

        return value;
    }
};