#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int dp[200001][2];
int solve(int i, int allow, unordered_map<int, list<int>> &adj, vector<int> &p)
{
    if (dp[i][allow] != -1)
    {
        return dp[i][allow];
    }

    int notSkip = ((allow == 0) ? 0 : p[i - 1]);
    int skip = 0;
    for (auto x : adj[i])
    {
        if (allow == 1)
        {
            notSkip += solve(x, 0, adj, p);
            skip += solve(x, 1, adj, p);
        }
        else
        {
            notSkip += solve(x, 1, adj, p);
        }
    }

    return dp[i][allow] = max(notSkip, skip);
}

int main()
{
    int N;
    cin >> N;

    vector<int> p(N);

    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(1, 1, adj, p) << endl;

    return 0;
}