class Solution
{
public:
    void dfs(string node, unordered_map<string, list<string>> &adj, unordered_map<string, bool> &visited)
    {
        visited[node] = true;

        for (auto &x : adj[node])
        {
            if (!visited[x])
            {
                dfs(x, adj, visited);
            }
        }
    }
    int numSimilarGroups(vector<string> &strs)
    {
        unordered_map<string, list<string>> adj;
        int n = strs.size();

        auto poss = [&](string a, string b)
        {
            int diff = 0;

            for (int i = 0; i < a.length(); i++)
            {
                if (a[i] != b[i])
                    diff++;
            }

            return diff == 2;
        };

        for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {

                if (poss(strs[i], strs[j]) || strs[i] == strs[j])
                {
                    adj[strs[i]].push_back(strs[j]);
                    adj[strs[j]].push_back(strs[i]);
                }
            }
        }

        unordered_map<string, bool> visited;
        int count = 0;
        for (auto x : strs)
        {
            if (!visited[x])
            {
                count++;
                dfs(x, adj, visited);
            }
        }
        return count;
    }
};