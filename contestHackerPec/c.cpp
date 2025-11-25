#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> r(n);
    vector<int> d(n);

    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    vector<vector<long long>> ans;

    for (int i = 0; i < n; i++)
    {
        ans.push_back({r[i] * d[i], r[i], i + 1});
    }

    auto cmp = [&](vector<long long> &a, vector<long long> &b)
    {
        if (a[0] != b[0])
        {
            return a[0] > b[0];
        }

        return a[1] > b[1];
    };

    sort(ans.begin(), ans.end(), cmp);
    vector<int> x;

    for (int i = 0; i < k; i++)
    {

        x.push_back(ans[i][2]);
    }
    sort(begin(x), end(x));
    for (auto y : x)
        cout << y << " ";

    cout << endl;

    return 0;
}