class Solution
{
public:
    bool dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, int node)
    {

        visited[node] = true;
        dfsvisited[node] = true;

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                if (dfs(adj, visited, dfsvisited, x))
                {
                    return true;
                }
            }
            else if (visited[x] && dfsvisited[x])
            {
                return true;
            }
        }

        dfsvisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;
        for (auto x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(adj, visited, dfsvisited, i))
                {
                    return false;
                }
            }
        }

        return true;
    }
};