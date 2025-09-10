class Solution
{
public:
    bool dfs(int node, int prev, unordered_map<int, list<int>> &adj, vector<bool> &hasApple, int &time)
    {
        time++; // entering this node
        bool checkApplePresent = hasApple[node];

        for (auto &ngb : adj[node])
        {
            if (ngb != prev)
            {
                checkApplePresent |= dfs(ngb, node, adj, hasApple, time);
            }
        }

        time += (checkApplePresent ? 1 : -1); // leaving this node
        return checkApplePresent;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {

        unordered_map<int, list<int>> adj;
        for (auto &x : edges)
        {
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }

        int time = 0;
        dfs(0, -1, adj, hasApple, time);
        return (time != 0 ? time - 2 : 0);
    }
};

// another way for same logic

// /DFS - O(V+E) - We visit all nodes and edges in the graph
class Solution
{
public:
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool> &hasApple)
    {
        int time = 0;

        for (int &child : adj[curr])
        {
            if (child == parent)
                continue;

            int time_from_bachha_log = DFS(adj, child, curr, hasApple);

            if (time_from_bachha_log || hasApple[child])
                time += 2 + time_from_bachha_log;
        }

        return time;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        unordered_map<int, vector<int>> adj;

        for (auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return DFS(adj, 0, -1, hasApple);
    }
};