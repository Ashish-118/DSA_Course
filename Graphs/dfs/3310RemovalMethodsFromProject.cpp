class Solution
{
public:
    vector<bool> visited;
    vector<int> indegree;
    unordered_map<int, list<int>> adj;

    void poss(int node)
    {

        visited[node] = true;

        for (auto &ngb : adj[node])
        {
            indegree[ngb]--;
            if (!visited[ngb])
            {
                poss(ngb);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>> &invocations)
    {
        visited.assign(n, false);
        indegree.assign(n, 0);

        for (auto x : invocations)
        {
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        bool result = true;

        poss(k);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] && indegree[i] != 0)
            {
                result = false;
                break;
            }
        }
        vector<int> ans;
        if (!result)
        {

            for (int i = 0; i < n; i++)
            {
                ans.push_back(i);
            }

            return ans;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
                ans.push_back(i);
        }

        return ans;
    }
};