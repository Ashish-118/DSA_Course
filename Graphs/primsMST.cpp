#include <bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) -
{
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);
    vector<int> key(n + 1);

    for (auto i : g)
    {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i <= n; i++)
    {
        mst[i] = false;
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    key[1] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // to find minimum key vertex
        for (int i = 1; i <= n; i++)
        {
            if (mst[i] == false && key[i] < mini)
            {
                mini = key[i];
                u = i;
            }
        }

        mst[u] = true;

        // update the key and parent of adjacent vertices
        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (mst[v] == false && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}
