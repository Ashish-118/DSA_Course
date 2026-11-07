#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<int>> adj;
vector<int> comp;

void buildComponents(int tar, int n)
{
    comp.assign(n + 1, -1);

    int id = 0;

    for (int ngb : adj[tar])
    {
        if (comp[ngb] != -1)
            continue;

        stack<int> st;
        st.push(ngb);
        comp[ngb] = id;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (int v : adj[node])
            {
                if (v == tar || comp[v] != -1)
                    continue;

                comp[v] = id;
                st.push(v);
            }
        }

        id++;
    }
}

bool check(int u, int v, int tar)
{
    if (u == tar || v == tar)
        return true;

    return comp[u] != comp[v];
}

void solve()
{
    int n;
    cin >> n;

    adj.assign(n + 1, {});

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n % 2 == 0)
    {
        cout << n + 1 << endl;
        return;
    }

    // Case 1: ans = n, target = n
    buildComponents(n, n);

    for (int i = 1; i <= n; i++)
    {
        int x = n - i;

        if (x >= 1 && x <= n && x != i)
        {
            if (check(i, x, n))
            {
                cout << n << endl;
                return;
            }
        }
    }

    // Case 2: ans = n + 1, target = (n/2) + 1
    int tar = (n / 2) + 1;

    buildComponents(tar, n);

    for (int i = 1; i <= n; i++)
    {
        int x = n + 1 - i;

        if (x >= 1 && x <= n && x != i)
        {
            if (check(i, x, tar))
            {
                cout << n + 1 << endl;
                return;
            }
        }
    }

    // Case 3: ans = n + 2, target = 1
    buildComponents(1, n);

    for (int i = 1; i <= n; i++)
    {
        int x = n + 2 - i;

        if (x >= 1 && x <= n && x != i)
        {
            if (check(i, x, 1))
            {
                cout << n + 2 << endl;
                return;
            }
        }
    }

    cout << n << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}