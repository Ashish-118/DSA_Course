// #include <iostream>
// #include <climits>
// using namespace std;

// int solve(int n, int x, int y, int z, vector<int> dp)
// {
//     if (n < 0)
//         return INT_MIN;
//     if (n == 0)
//         return 0;

//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     int lenx = solve(n - x, x, y, z, dp) + 1;
//     int leny = solve(n - y, x, y, z, dp) + 1;
//     int lenz = solve(n - z, x, y, z, dp) + 1;
//     dp[n] = max(max(lenx, leny), lenz);

//     return dp[n];
// }

// int cutSegments(int n, int x, int y, int z)
// {
//     vector<int> dp(n + 1, -1);
//     int ans = solve(n, x, y, z, dp);
//     if (ans < 0)
//         return 0;
//     else
//         return ans;
// }

/// tabulation

#include <iostream>
#include <climits>
using namespace std;

int solve(int n, int x, int y, int z, vector<int> dp)
{
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int lenx = INT_MIN;
        int leny = INT_MIN;
        int lenz = INT_MIN;
        if (i >= x)
            lenx = dp[i - x] + 1;
        if (i >= y)
            leny = dp[i - y] + 1;
        if (i >= z)
            lenz = dp[i - z] + 1;
        dp[i] = max(max(lenx, leny), lenz);
    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    else
        return ans;
}