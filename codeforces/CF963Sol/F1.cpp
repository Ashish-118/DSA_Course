#include <bits/stdc++.h>
using namespace std;

void chmod(int &x, int k)
{
    if (x >= k)
        x -= k;
    if (x < 0)
        x += k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, w, h;
        int64_t k;
        string s;
        cin >> n >> k >> w >> h >> s;
        int x = 0, y = 0;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'U')
                y++;
            if (s[i] == 'D')
                y--;
            if (s[i] == 'L')
                x--;
            if (s[i] == 'R')
                x++;
            chmod(x, 2 * w);
            chmod(y, 2 * h);
            mp[{x, y}]++;
            cout<<mp[{x,y}]<<endl;
        }

        int64_t ans = 0;
        for (int i = 0; i < k; i++)
        {
            int p = (1LL * i * x) % (2 * w);
            int q = (1LL * i * y) % (2 * h);
            if (p > 0)
                p -= 2 * w;
            if (q > 0)
                q -= 2 * h;
            ans += mp[{-p, -q}];
            cout<<"p "<<p<<" q "<<q<<endl;
        }
        cout << ans << '\n';
    }
}
