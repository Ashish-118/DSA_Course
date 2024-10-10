#include <bits/stdc++.h>
#define int long long
using namespace std;

int max(int x, int y, char operation, int n, vector<int> &v)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int max_value = INT_MIN;
    while (s <= e)
    {
        if ((x > v[n - 1] && y > v[n - 1]) || (x < v[0] && y < v[0]))
        {
            s = 1;
            e = 0;
            break;
        }

        else if ((v[s] == x || x < v[0]) && (v[e] == y || y > v[n - 1]))
        {

            break;
        }
        else if (v[mid] < x)
        {
            s = mid + 1;
        }
        else if (v[mid] > y)
        {
            e = mid - 1;
        }
        else
        {

            if (v[s] != x && x >= v[0])
            {
                s++;
            }
            if (v[e] != y && y <= v[n - 1])
            {

                e--;
            }
        }
        mid = s + (e - s) / 2;
    }

    if (operation == '+')
    {
        for (int i = s; i <= e; i++)
        {
            v[i]++;
        }
    }
    else
    {
        
        for (int i = s; i <= e; i++)
        {
            v[i]--;
        }
    }
    max_value = *max_element(v.begin(), v.end());

    return max_value;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        vector<char> operate(m);
        vector<int> a1(m);
        vector<int> a2(m);
        vector<int> ans(m);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < m; i++)
        {
            sort(v.begin(), v.end());

            cin >> operate[i] >> a1[i] >> a2[i];

            cout << max(a1[i], a2[i], operate[i], n, v) << " ";
  
        }
        cout << endl;
    }
    return 0;
}