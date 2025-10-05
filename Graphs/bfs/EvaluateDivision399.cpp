class Solution
{
public:
    double bfs(string start, string destination, unordered_map<string, list<pair<string, double>>> &adj)
    {
        unordered_map<string, bool> visited;
        queue<pair<string, double>> q;
        q.push({start, 1});

        double ans = -1;

        visited[start] = true;

        if (adj.count(start) == 0)
            return -1;

        while (!q.empty())
        {
            auto front = q.front();
            string node = front.first;
            double currVal = front.second;
            q.pop();

            if (node == destination)
            {
                ans = currVal;
                break;
            }

            for (auto &ngb : adj[node])
            {
                if (!visited[ngb.first])
                {

                    q.push({ngb.first, currVal * ngb.second});

                    visited[ngb.first] = true;
                }
            }
        }

        return ans;
    }

    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {

        unordered_map<string, list<pair<string, double>>> adj;
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> ans;

        for (auto &query : queries)
        {
            string start = query[0];
            string dest = query[1];

            ans.push_back(bfs(start, dest, adj));
        }

        return ans;
    }
};