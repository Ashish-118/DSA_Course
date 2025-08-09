#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxBouquetCost(string flowers, int p, int q)
{
    int n = flowers.size();
    vector<int> dp(n + 1, 0); // dp[i] = max cost from index i

    for (int i = n - 1; i >= 0; --i)
    {
        dp[i] = dp[i + 1]; // Option: skip

        // Option 1: 2-length bouquet (1 rose + 1 lily in any order)
        if (i + 1 < n)
        {
            if ((flowers[i] == '0' && flowers[i + 1] == '1') ||
                (flowers[i] == '1' && flowers[i + 1] == '0'))
            {
                dp[i] = max(dp[i], q + dp[i + 2]);
            }
        }

        // Option 2: 3-length bouquet (3 roses)
        if (i + 2 < n)
        {
            if (flowers[i] == '0' && flowers[i + 1] == '0' && flowers[i + 2] == '0')
            {
                dp[i] = max(dp[i], p + dp[i + 3]);
            }
        }
    }

    return dp[0];
}

int main()
{
    string flowers;
    int p, q;

    // Example: input = "0100010", p = 10, q = 5
    cin >> flowers >> p >> q;

    cout << maxBouquetCost(flowers, p, q) << endl;

    return 0;
}
