#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

    int n, w;
    cin >> n >> w;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + v[i] <= w)
        {
            sum += v[i];
        }
        else
        {
            count++;
            sum=0;
        }
    }
    cout<<count<<endl;

    return 0;
}