#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        map<int, int> user_map;
        int user;
        for (int i = 0; i < n; i++)
        {
            cin >> user;
            user_map[user]++;
        }

        // max occurence
        int max = INT_MIN;
        for (auto it = user_map.cbegin(); it != user_map.cend(); ++it)
        {

            if (it->second > max)
            {
                max = it->second;
            }
        }

        // cout << max;
        cout << n - max << endl;
    }
    return 0;
}