#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> findSubsets(vector<int> &v1)
{
    vector<vector<int>> subsets;
    int n = v1.size();

    int subsetCount = (1 << n);

    for (int mask = 0; mask < subsetCount; ++mask)
    {
        vector<int> subset;

        for (int i = 0; i < n; ++i)
        {

            if (mask & (1 << i))
            {
                subset.push_back(v1[i]);
            }
        }
        subsets.push_back(subset);
    }

    return subsets;
}

int findXOR(const vector<int> &v1)
{
    int xorResult = 0;

    for (int num : v1)
    {
        xorResult ^= num;
    }

    return xorResult;
}

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        for (int i = 0; i < n; i++)
            cin >> v2[i];

        vector<int> probable(pow(2, n) - 1);
        vector<vector<int>> subsets = findSubsets(v1);

                for (int i = 1; i <= pow(2, n) - 1; i++)
        {
            probable[i] =
        }
    }

    return 0;
}