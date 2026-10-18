#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int maxi = LLONG_MIN;
        if (i > 0 && a[i - 1] > a[i])
        {
            maxi = a[i - 1];
        }
        if (i < n - 1 && a[i + 1] > a[i])
        {
            maxi = max(maxi, a[i + 1]);
        }

        if (maxi == LLONG_MIN)
            continue;

        int idx = log2(maxi);

        int temp = 0;

        for (int j = idx; j >= 0; j--)
        {

            if ((maxi & (1LL << j)) == 0)
            {
                continue;
            }
            int temp2 = temp | ((1LL << j) - 1);

            // cout<<" temp2 "<<temp2<<endl;

            if (temp2 >= a[i])
            {
                temp |= ((1LL << j) - 1);
                break;
            }

            temp |= (1LL << j);

            // cout<<" temp "<<temp<<endl;
        }
        // cout<<"maxi "<<maxi<<" idx "<<idx<<" temp "<<temp<<endl;
        a[i] = temp;
    }

    int ans = 0;
    for (auto x : a)
    {
        // cout<<x<<" ";
        ans |= x;
    }
    // cout<<endl;

    cout << ans << endl;
    // cout<<"hi"<<endl;
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