// Approach-1 - Using DFS
// T.C : O(n^2)
// S.C : O(n)
class Solution
{
public:
    bool dfs(unordered_map<int, vector<int>> &adj, int u, int v, vector<bool> &visited)
    {
        visited[u] = true;

        if (u == v)
        {
            return true;
        }

        for (int &ngbr : adj[u])
        {
            if (visited[ngbr])
                continue;

            if (dfs(adj, ngbr, v, visited))
            {
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        // number of nodes = n
        // number of edges = n

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            vector<bool> visited(n, false);
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() && dfs(adj, u, v, visited))
            {
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};

// using dsu

class Solution
{
public:
    int findParent(int node, vector<int> &parent)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    void dsu(vector<int> &rank, vector<int> &parent, int u, int v)
    {
        if (rank[u] > rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
        else if (rank[u] < rank[v])
        {
            parent[u] = v;
            rank[v]++;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> rank(n + 1, 0);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto x : edges)
        {
            int parent_u = findParent(x[0], parent);
            int parent_v = findParent(x[1], parent);
            if (parent_u != parent_v)
            {
                dsu(rank, parent, parent_u, parent_v);
            }
            else
            {
                return x;
            }
        }
        return {};
    }
};