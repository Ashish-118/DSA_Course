#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();

        vector<int> prefixEven(n, 0);
        vector<int> suffixOdd(n, 0);

        // Number of 2's in prefix [0...i]
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '2')
            {
                prefixEven[i] = 1;
            }

            if (i > 0)
            {
                prefixEven[i] += prefixEven[i - 1];
            }
        }

        // Number of 1's and 3's in suffix [i...n-1]
        for (int i = n - 1; i >= 0; i--)
        {
            if ((s[i] - '0') & 1)
            {
                suffixOdd[i] = 1;
            }

            if (i < n - 1)
            {
                suffixOdd[i] += suffixOdd[i + 1];
            }
        }

        int best = 0;

        for (int i = 0; i < n; i++)
        {
            int two = prefixEven[i];
            int oneThree = suffixOdd[i];

            best = max(best, two + oneThree);
        }

        cout << n - best << '\n';
    }
}