class Solution
{
public:
    int dfs(int node, int parent, string &s, int &ans, vector<vector<int>> &adj)
    {
        int firstLargest = 0, secondLargest = 0;

        for (auto ngb : adj[node])
        {
            if (ngb == parent)
                continue;

            int val = dfs(ngb, node, s, ans, adj);

            if (s[node] != s[ngb])
            {
                if (val >= firstLargest)
                {
                    secondLargest = firstLargest;
                    firstLargest = val;
                }
                else if (val > secondLargest)
                {
                    secondLargest = val;
                }
            }
        }

        ans = max(ans, firstLargest + secondLargest + 1);
        return 1 + firstLargest;
    }

    int longestPath(vector<int> &parent, string s)
    {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
        { // skip root (parent[0] == -1)
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        int ans = 0;
        dfs(0, -1, s, ans, adj);
        return ans;
    }
};
