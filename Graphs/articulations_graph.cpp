// User function Template for C++
class Solution
{
    void solve(int node, int parent, int &timer, vector<int> adj[],
               vector<bool> &visited, vector<int> &disc,
               vector<int> &low, set<int> &result)
    {

        visited[node] = true;
        disc[node] = low[node] = timer++;
        int children = 0;

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                children++;
                solve(x, node, timer, adj, visited, disc, low, result);

                low[node] = min(low[node], low[x]);

                // Non-root node condition
                if (parent != -1 && low[x] >= disc[node])
                {
                    result.insert(node);
                }
            }
            else if (x != parent)
            {
                low[node] = min(low[node], disc[x]);
            }
        }

        // Root node condition
        if (parent == -1 && children > 1)
        {
            result.insert(node);
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        set<int> result;
        int timer = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                solve(i, -1, timer, adj, visited, disc, low, result);
            }
        }

        return result.empty() ? vector<int>{-1} : vector<int>(result.begin(), result.end());
    }
};
