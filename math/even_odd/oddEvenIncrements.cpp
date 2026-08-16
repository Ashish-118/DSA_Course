#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        auto parity = [&](int x)
        {
            return (x & 1 ? 1 : 0);
        }

        int check = parity(arr[0]);
        bool poss = true;

        for (int i = 2; i < n; i += 2)
        {
            if (parity(arr[i]) != check)
            {
                poss = false;
                break;
            }
        }

        if (poss)
        {
            check = parity(arr[1]);

            for (int i = 3; i < n; i += 2)
            {
                if (parity(arr[i]) != check)
                {
                    poss = false;
                    break;
                }
            }

            if (poss)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}