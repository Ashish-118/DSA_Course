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
        int n, q;
        cin >> n >> q;
        vector<string> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        for (int i = 0; i < q; i++)
        {
            int diff = 0;
            int sum = -1;
            int x, y;
            cin >> x >> y;

            int right = y - 1, left = y - 1;
            if (vec[x - 1].find(vec[y - 1][0]) != string::npos || vec[x - 1].find(vec[y - 1][1]) != string::npos)
            {

                sum = abs(x - y);
            }
            else
            {

                int i = y;
                for (; i < n; i++) // right
                {
                    right++;
                    if ((vec[i].find(vec[y - 1][0]) != string::npos || vec[i].find(vec[y - 1][1]) != string::npos) && (vec[i].find(vec[x - 1][0]) != string::npos || vec[i].find(vec[x - 1][1]) != string::npos))
                    {
                        break;
                    }
                }

                int j = y - 2;
                for (; j > -1; j--) // left1
                {
                    left--;
                    if ((vec[j].find(vec[y - 1][0]) != string::npos || vec[j].find(vec[y - 1][1]) != string::npos) && (vec[j].find(vec[x - 1][0]) != string::npos || vec[j].find(vec[x - 1][1]) != string::npos))
                    {
                        break;
                    }
                }

                if (j != -1 || i != n)
                {
                    if (j != -1 && i != n)
                    {

                        sum = min(abs(right - (x - 1)) + abs(right - (y - 1)), abs(left - (x - 1)) + abs(left - (y - 1)));
                    }
                    else if (j == -1)
                    {
                        sum = abs(right - (x - 1)) + abs(right - (y - 1));
                    }
                    else
                    {
                        sum = abs(left - (x - 1)) + abs(left - (y - 1));
                    }
                }
                else
                {
                    sum = -1;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}