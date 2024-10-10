#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int count = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (abs(a[i + 1] - a[i]) > k)
            {
                if (i + 1 - count < a.size() - i - 1)
                {
                    count = count + i + 1 - count;
                }
                else
                {
                    count = count + a.size() - i - 1;
                    break;
                }
            }
        }
     
        cout << count << endl;
    }

    return 0;
}