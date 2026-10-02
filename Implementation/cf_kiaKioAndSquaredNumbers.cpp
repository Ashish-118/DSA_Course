#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pp pair<int, int>

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;

    auto fn = [&](int x)
    {
        int sum = 0;
        string s = to_string(x);
        for (auto x : s)
        {
            sum += (x - '0') * (x - '0');
        }
        return sum;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            unordered_map<int, int> s1;
            unordered_map<int, int> s2;
            int temp = a[i];
            int idx = 0;
            while (s1.count(temp) == 0)
            {
                s1[temp] = idx++;
                temp = fn(temp);
            }

            temp = a[j];
            idx = 0;
            while (s2.count(temp) == 0)
            {
                s2[temp] = idx++;
                temp = fn(temp);
            }

            bool check = false;
            for (auto x : s1)
            {
                if (s2.count(x.first))
                {
                    if ((s1[x.first] - s2[x.first]) == -(s1.size() - s2.size()))
                    {
                        check = true;
                        break;
                    }
                }
            }

            if (check)
            {
                count++;
            }
        }
    }

    cout << count << endl;
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