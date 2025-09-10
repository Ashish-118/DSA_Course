class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {

        vector<bool> visited(n, false);
        unordered_map<int, list<int>> adj;
        for (auto &x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == destination)
                return true;

            for (auto ngb : adj[node])
            {
                if (!visited[ngb])
                {
                    q.push(ngb);
                    visited[ngb] = true;
                }
            }
        }
        return false;
    }
};