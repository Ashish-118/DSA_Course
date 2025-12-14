class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>> &queries)
    {
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < n - 1; i++)
        {
            adj[i].push_back(i + 1);
        }
        vector<bool> visited(n, false);
        vector<int> ans;

        for (auto query : queries)
        {
            adj[query[0]].push_back(query[1]);

            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0] = true;
            int totalNodes = 0;
            while (!q.empty())
            {
                auto p = q.front();
                int node = p.first;
                int lvl = p.second;
                q.pop();

                if (node == n - 1)
                {
                    ans.push_back(lvl);
                    break;
                }

                for (auto ngb : adj[node])
                {
                    if (!visited[ngb])
                    {
                        q.push({ngb, lvl + 1});
                        visited[ngb] = true;
                    }
                }
            }

            fill(visited.begin(), visited.end(), false);
        }

        return ans;
    }
};