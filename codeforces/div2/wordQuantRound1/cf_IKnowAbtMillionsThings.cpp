#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    if (n == 1 || odd % 2 == 0)
    {
        cout << "Moggity" << endl;
    }
    else if (odd >= 3 && (odd - 3 + even) > 0)
    {
        cout << "Moggity" << endl;
    }
    else if (odd == 1 && even >= 2)
    {
        cout << "Moggity" << endl;
    }
    else
    {
        cout << "Larpity" << endl;
    }
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