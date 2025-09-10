class Solution
{
public:
    bool bfs(unordered_map<int, list<int>> &adj, int node, vector<int> &types)
    {
        queue<pair<int, int>> q;

        q.push({node, 0});
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int node = front.first;
            int type = front.second;

            for (auto &ngb : adj[node])
            {
                if (types[ngb] == -1)
                {
                    types[ngb] = !type;
                    q.push({ngb, types[ngb]});
                }
                else if (types[ngb] == type)
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {

        unordered_map<int, list<int>> adj;
        vector<int> types(n + 1, -1);
        for (auto &x : dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        bool ans = true;
        for (int i = 1; i <= n; i++)
        {
            if (types[i] == -1 && ans)
            {
                ans = ans && bfs(adj, i, types);
            }
        }
        return ans;
    }
};