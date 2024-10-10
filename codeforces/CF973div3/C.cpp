

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
        vector<int> v(n);  
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int mid = n / 2;
        int sum = accumulate(v.begin(), v.end(), 0LL);  

        if (n == 1 || n == 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int x = (v[mid] * (2 * n)) - sum;
            cout << (x >= 0 ? x + 1 : 0) << endl;
        }
    }

    return 0;
}
