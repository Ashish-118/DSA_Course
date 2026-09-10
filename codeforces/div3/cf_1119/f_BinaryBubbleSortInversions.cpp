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
    string s;
    cin >> s;

    map<int, int, greater<int>> mp;

    vector<int> no_of_zeroes(n, 0);
    int no_of_ones_has_inversions = 0;
    int scores = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            no_of_zeroes[i] = 1;
        }
        if (i < n - 1)
        {
            no_of_zeroes[i] += no_of_zeroes[i + 1];
        }

        if (a[i] == 1 && no_of_zeroes[i] > 0)
        {
            mp[no_of_zeroes[i]]++;
            no_of_ones_has_inversions++;
            scores += no_of_zeroes[i];
        }
    }

    // cout<<no_of_ones_has_inversions<<endl;

    // for(auto x:mp){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    cout << scores << " ";
    int r = 0;
    for (auto x : s)
    {
        if (x == '0')
        {
            r++;
            scores -= no_of_ones_has_inversions;

            no_of_ones_has_inversions -= mp[r];

            mp.erase(r);

            cout << scores << " ";
        }
        else
        {
            if (mp.empty())
            {
                cout << "0 ";
                continue;
            }
            auto it = mp.begin();

            int key = it->first;
            int value = it->second;

            mp[key]--;
            scores -= (key - r);
            if (mp[key] == 0)
            {
                mp.erase(key);
            }
            no_of_ones_has_inversions--;
            cout << scores << " ";
        }
    }

    cout << endl;
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