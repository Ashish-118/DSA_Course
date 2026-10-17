
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tot = 0;

    // Calculate total ugliness
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            tot += arr[i];
        }
        else
        {
            tot += abs(arr[i] - arr[i - 1]);
        }
    }

    tot += arr[n - 1];

    // Handle internal bars
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            tot -= arr[i] - max(arr[i - 1], arr[i + 1]);
            arr[i] = max(arr[i - 1], arr[i + 1]);
        }
    }

    // Handle first and last bars
    if (n > 1)
    {
        if (arr[0] > arr[1])
        {
            tot -= arr[0] - arr[1];
        }

        if (arr[n - 1] > arr[n - 2])
        {
            tot -= arr[n - 1] - arr[n - 2];
        }
    }
    else
    {
        tot = arr[0];
    }

    cout << tot << '\n';
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
