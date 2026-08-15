#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> arr(n);
        long long total_transfer_sum=0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total_transfer_sum+=(arr[i]/x)*y;
        }

        long long ans=0;

        for(int i=0; i<n; i++){
            ans=max(ans, total_transfer_sum-((arr[i]/x)*y)+arr[i]);
        }

       

        cout << ans << endl;
    }

    return 0;
}

