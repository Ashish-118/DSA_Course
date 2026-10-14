#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int m, k;
    cin >> m >> k;

    vector<int> v;
    unordered_map<int, int> mp_freq;
    unordered_map<int, int> mp2;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int steps = 0;

        if (a == b && b == c)
        {
            steps = -1;
        }
        else if (a <= b && b <= c && a <= c)
        {

            int m1 = LLONG_MAX;
            int m2 = LLONG_MAX;
            int m3 = LLONG_MAX;
            if (a < c)
            {
                m1 = b - (a - 1);
            }

            if (a < b)
            {
                m2 = c - (a - 1);
                m3 = c - (b - 1);
            }

            int mini = min({m1, m2, m3});
            steps = mini;
        }

        mp_freq[a + b + c]++;

        if (steps == -1)
        {
            mp2[a + b + c] = -1;
        }
        mp2[a + b + c] += (mp2[a + b + c] == -1 ? 0 : steps);
    }

    for (auto it : mp_freq)
    {
        v.push_back(it.first);
    }

    sort(begin(v), end(v));

    int n = v.size();
    int i = 0;

    while (k >= 0 && i < n - 1)
    {
        // cout<<" i "<<i<<" k "<<k<<endl;
        int curr = v[i];
        int next = v[i + 1];

        // cout<<" curr "<<curr<<" next "<<next<<endl;

        if (mp2[curr] == -1 || 2 * mp2[curr] >= k)
        {
            cout << curr << endl;
            return;
        }

        k -= 2 * mp2[curr];

        int freq = mp_freq[curr];
        int diff = next - curr;

        int mini = min(diff, k / mp_freq[curr]);
        curr += mini;
        // cout<<" k before "<<k<<endl;
        k -= mini * freq;
        //  cout<<" k after "<<k<<endl;

        mp_freq[curr] += freq;

        if (k == 0 || diff != mini)
        {
            cout << curr << endl;
            return;
        }

        i++;
    }

    if (i == n - 1)
    {

        int curr = v[i];
        if (mp2[curr] == -1 || 2 * mp2[curr] >= k)
        {
            cout << curr << endl;
            return;
        }
        k -= 2 * mp2[curr];

        int mini = k / mp_freq[curr];
        curr += mini;
        cout << curr << endl;
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
