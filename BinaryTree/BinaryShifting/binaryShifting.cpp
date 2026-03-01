#include <bits/stdc++.h>
using namespace std;

const int MAX = 17; // because 2^17 > 1e5(10^5)== log2(1e5) ~ 16.6
vector<vector<int>> table;

void build(vector<int> &parent)
{
    int n = parent.size();
    table.assign(MAX, vector<int>(n));

    // 2^0 ancestor (direct parent)
    for (int i = 0; i < n; i++)
        table[0][i] = parent[i];

    // Fill table
    for (int i = 1; i < MAX; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i - 1][j] == -1)
                table[i][j] = -1;
            else
                table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int query(int node, int k)
{

    for (int i = 0; i < MAX; i++)
    {
        if (k & (1 << i))
        {
            node = table[i][node];
            if (node == -1)
                return -1;
        }
    }
    return node;
}