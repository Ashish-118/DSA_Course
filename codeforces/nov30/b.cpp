#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        string body;
        cin >> body;

        int count = 0;
        int time = 0;
        for (int i = 0; i < n;)
        {

            if (body[i] == '0')
                count++;
            else
                count = 0;

            if (count == m)
            {
                int j = 0;
                for (; j < k; j++)
                {
                    if ((i + j) < n)
                        body[i + j] = '1';
                    else
                        break;
                }
                count = 0;
                i = i + j;
                time++;
                continue;
            }
            i++;
        }

        cout << time << endl;
    }
    return 0;
}