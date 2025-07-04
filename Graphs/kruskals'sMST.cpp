#include <bits/stdc++.h>

void Initialize(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i <= n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
    vector<int> parent(n + 1), rank(n + 1);
    Initialize(parent, rank, n);
    sort(edges.begin(), edges.end(), cmp);
    int weight = 0;
    for (auto x : edges)
    {

        int u = findParent(parent, x[0]);
        int v = findParent(parent, x[1]);
        int wt = x[2];

        if (u != v)
        {
            weight += wt;
            unionSet(parent, rank, u, v);
        }
    }
    return weight;
}
