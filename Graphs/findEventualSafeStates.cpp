class Solution
{
public:
    bool dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        visited[node] = true;
        dfsVisited[node] = true;

        for (int &x : adj[node])
        {
            if (!visited[x])
            {
                if (dfs(x, adj, visited, dfsVisited))
                {
                    return true;
                }
            }
            else if (visited[x] && dfsVisited[x])
            {
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;

        for (int i = 0; i < graph.size(); i++)
        {
            for (auto &x : graph[i])
            {
                adj[i].push_back(x);
            }
        }

        for (int i = 0; i < graph.size(); i++)
        {
            if (!visited[i])
            {

                dfs(i, adj, visited, dfsVisited);
            }
        }

        vector<int> result;

        for (int i = 0; i < graph.size(); i++)
        {
            if (!dfsVisited[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
};