#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int noOfOnes = 0;

        for (int i = 0; i < 2 * n; i++)
        {
            int x;
            cin >> x;

            if (x == 1)
            {
                noOfOnes++;
            }
        }

        int maxi = -1;
        if (noOfOnes == 2 * n)
        {
            maxi = 0;
        }
        else if (noOfOnes > n)
        {
            maxi = n - (noOfOnes % n);
        }
        else
        {
            maxi = noOfOnes;
        }

        cout << (noOfOnes & 1 ? 1 : 0) << " " << maxi << endl;
    }
    return 0;
}