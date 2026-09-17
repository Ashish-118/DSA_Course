#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mod 998244353

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> no_of_trees(n + 1, 0);
    vector<int> sum_of_trees(n + 1, 0);

    no_of_trees[1] = 1;
    sum_of_trees[1] = 0;

    sort(a.begin(), a.end(), greater<int>());

    int currSum = a[0];

    for (int j = 1; j < n; j++)
    {
        int i = j + 1;
        int score_to_add_for_one_tree = (currSum - ((i - 1) * a[j]) % mod + mod) % mod;
        int score_to_add_for_all_trees = (no_of_trees[i - 1] * score_to_add_for_one_tree) % mod;

        sum_of_trees[i] = (((i - 1) * sum_of_trees[i - 1]) % mod + score_to_add_for_all_trees) % mod;
        no_of_trees[i] = (no_of_trees[i - 1] * (i - 1)) % mod;
        currSum = (currSum + a[j]) % mod;
    }

    cout << sum_of_trees[n] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}