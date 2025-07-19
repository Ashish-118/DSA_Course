#include <iostream>
using namespace std;

int solve(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &profit, unordered_map<int, bool> &sold)
{
    visited[node] = true;
    int pro = 0;

    for (auto x : adj[node])
    {
        if (!adj.find(x))
        {
            pro += (2 * profit[x]);
        }
        else
        {
            if (!visited[x])
            {
                pro += solve(x, adj, visited, profit, sold);
            }

            int n1 = 0;
            n2 = 2 * profit[x];

            for (auto i : adj[x])
            {
                if (!sold[i])
                {
                    n1 += (2 * profit[i]);
                }
            }
            if (n1 > n2)
                pro += profit[x];
            else
                pro += (2 * profit[x]);

            sold[x] = true;
        }
    }
    return pro;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> profit(n + 1, -1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> profit[i];
        }
        unordered_map<int, bool> visited;
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> sold;

        for (int i = 1; i <= n; ++i)
        {
            int u;
            cin >> u;
            adj[u].push_back(i);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                solve(i, adj, visited, profit, sold);
            }
        }
    }

    return 0;
}