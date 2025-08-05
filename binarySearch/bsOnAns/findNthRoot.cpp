class Solution
{
public:
    int nthRoot(int n, int m)
    {
        if (m == 0 || m == 1)
            return m;

        int l = 1, r = m;
        int ans = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if ((long long)pow(mid, n) <= m)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (pow(ans, n) != m)
            return -1;

        return ans;
    }
}; //--------------------

#include <bits/stdc++.h>
using namespace std;

// return 1, if == m:
// return 0, if < m:
// return 2, if > m:
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}