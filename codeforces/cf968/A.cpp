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
        string user;

        cin >> user;
        string copy = user;
        sort(copy.begin(), copy.end());
        string unique;

        for (char c : copy)
        {
            if (unique.find(c) == string::npos)
            {
                unique += c;
            }
        }

        int i = 0;
        while (user.size() != 0 && unique.size() != i)
        {
            int x = user.find(unique[i]);
            if (x != string::npos && x != -1)
            {
                user.erase(x, 1);
            }

            int y = user.find(unique[i]);
            while ((user.size() - 1) >= (y + 1) && user[y + 1] == user[y])
            {
                y++;
            }

            if (y != string::npos && y != -1 )
            {
                user.erase(x, y - x + 1);
            }

            i++;
        }

        if (user.size() == 0 && i!=1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}