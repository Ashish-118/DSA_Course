#include <bits/stdc++.h>
using namespace std;

void solve(int node, int parent, int &timer, unordered_map<int, list<int>> &adj,
           unordered_map<int, bool> &visited, vector<int> &disc,
           vector<int> &low, vector<vector<int>> &result)
{

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto x : adj[node])
    {
        if (!visited[x])
        {
            solve(x, node, timer, adj, visited, disc, low, result);

            // On backtracking, update low[node]
            low[node] = min(low[node], low[x]);

            if (disc[node] < low[x])
            {
                result.push_back({node, x});
            }
        }
        else if (x != parent)
        {
            low[node] = min(low[node], disc[x]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for (auto x : edges)
    {
        int u = x[0];
        int v = x[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> low(v, -1);
    vector<int> disc(v, -1);
    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            solve(i, -1, timer, adj, visited, disc, low, result);
        }
    }

    return result;
}
