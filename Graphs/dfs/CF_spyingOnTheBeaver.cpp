#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define endl '\n'

vector<int> depth;
unordered_map<int, list<int>> adj;
vector<int> parent;

void dfs(int node, int par)
{

    for (auto ngb : adj[node])
    {
        if (ngb == par)
            continue;
        
        depth[ngb] = depth[node] + 1;
        dfs(ngb, node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        depth.erase(depth.begin(), depth.end());
        adj.clear();

        parent.erase(parent.begin(), parent.end());
        
        
        int n;
        cin >> n;

        parent.assign(n + 1, 0);

        for (int i = 2; i <= n; i++)
        {
            cin >> parent[i];

            adj[parent[i]].push_back(i);
        }

        int m;
        cin >> m;
        vector<int> a;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }

        depth.assign(n + 1, 0);

        dfs(1, 0);

        int miniDepthNode = INT_MAX;

        for (auto x : a)
        {
            if (depth[x] < miniDepthNode)
            {
                miniDepthNode = x;
            }
        }

        cout << m - 1 << " ";

        for (auto x : a)
        {
            if (x != miniDepthNode)
            {
                cout << x << " ";
            }
        }
        cout << endl;
    }
    return 0;
}