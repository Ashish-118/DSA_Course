#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> parent, level;

void dfs(int node, int par, int lvl)
{
    parent[node] = par;
    level[node] = lvl;

    for (int child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node, lvl + 1);
        }
    }
}

int lca(int u, int v)
{

    // Make sure v is deeper or equal
    if (level[u] > level[v])
        swap(u, v);

    // Bring v to same level as u
    while (level[v] > level[u])
        v = parent[v];

    // If equal now
    if (u == v)
        return u;

    // Move both up until equal
    while (u != v)
    {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    adj.assign(n + 1, {});
    parent.assign(n + 1, -1);
    level.assign(n + 1, 0);

    // Input edges
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Assume root is 1
    dfs(1, -1, 0);

    int q;
    cin >> q;

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}

// time complexity: O(n + q * n)