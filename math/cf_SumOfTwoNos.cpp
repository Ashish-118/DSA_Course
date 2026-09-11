#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    string x = "", y = "";
    string num = to_string(n);
    int len = num.length();

    int gainX = 0;

    for (int i = 0; i < len; i++)
    {
        int rem = (num[i] - '0') % 2;
        int v = (num[i] - '0') / 2;

        if (rem)
        {
            if (gainX)
            {
                x += (v + '0');
                y += (v + 1 + '0');
                gainX = 0;
            }
            else
            {
                x += (v + 1 + '0');
                y += (v + '0');
                gainX = 1;
            }
        }
        else
        {
            x += (v + '0');
            y += (v + '0');
        }
    }

    cout << stoi(x) << " " << stoi(y) << endl;
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