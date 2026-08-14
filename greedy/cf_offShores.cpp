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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> rem(n);
        for (int i = 0; i < n; i++)
        {
            rem[i] = arr[i] % x;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (rem[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < n && arr[curr]; i++)
            {

                if (rem[i] == 0)
                    continue;

                int times = arr[curr] / x;
                for (int j = 1; j <= times; j++)
                {
                    if ((rem[i] + (j * y)) % x == 0)
                    {
                        arr[i] += j * y;
                        rem[i] = 0;
                        q.push(i);
                        arr[curr] -= j * x;
                        break;
                    }
                }
            }
        }

        int idx = max_element(rem.begin(), rem.end()) - rem.begin();
        if (rem[idx] == 0)
        {
            int maxiElementIdx = max_element(arr.begin(), arr.end()) - arr.begin();
            idx = maxiElementIdx;
        }

        // for(int i=0; i<n; i++){
        //     cout<<"i "<<i<<" rem "<<rem[i]<<" val "<<arr[i]<<endl;
        // }

        int ans = arr[idx];

        for (int i = 0; i < n; i++)
        {
            if (i != idx)
            {
                ans += ((arr[i] / x) * y);
            }
        }

        cout << ans << endl;
    }

    return 0;
}

