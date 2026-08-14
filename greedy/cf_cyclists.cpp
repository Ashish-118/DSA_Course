#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    // --------------------------------------------------
    // Cost before the FIRST time we play the target
    // --------------------------------------------------

    int first = 0;

    if (p <= k)
    {
        // Target is already playable.
        first = v[p];
    }
    else
    {
        multiset<int> st;

        // Initially playable cards
        for (int i = 1; i <= k; i++)
        {
            st.insert(v[i]);
        }

        // Need p-k cards to be moved before target
        // enters the first k positions.
        for (int i = k + 1; i <= p; i++)
        {

            // Play cheapest currently playable card
            first += *st.begin();

            st.erase(st.begin());

            // Don't insert the target itself.
            if (i < p)
            {
                st.insert(v[i]);
            }
        }

        // Now target has become playable.
        first += v[p];
    }

    // Can't even play target once.
    if (first > m)
    {
        cout << 0 << '\n';
        return;
    }

    // --------------------------------------------------
    // Cost of EVERY SUBSEQUENT target play
    // --------------------------------------------------

    vector<int> other;

    for (int i = 1; i <= n; i++)
    {
        if (i != p)
        {
            other.push_back(v[i]);
        }
    }

    sort(other.begin(), other.end());

    int cycle = v[p];

    // After target goes to the back, exactly n-k
    // other cards need to be played.
    for (int i = 0; i < n - k; i++)
    {
        cycle += other[i];
    }

    // First target play already happened.
    // How many more complete cycles can we afford?
    int ans = 1 + (m - first) / cycle;

    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}