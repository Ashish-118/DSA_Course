class Solution
{
public:
    int t[20001];
    // int solve(int i, int j, string s, vector<vector<bool>>& isPalindrome) {
    //     if (i > j)
    //         return 0;
    //     if (t[i]!= -1)
    //         return t[i];
    //     int ans = INT_MAX;

    //     for (int k = i; k <= j; k++) {
    //         if (isPalindrome[i][k]) {
    //             ans = min(ans, solve(k + 1, j, s, isPalindrome));
    //         }
    //     }

    //     return t[i] = ans + 1;
    // }

    int minCut(string s)
    {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, 0));

        for (int l = 1; l <= n; l++)
        {
            for (int i = 0; i + l - 1 < n; i++)
            {
                int j = i + l - 1;

                if (i == j)
                    isPalindrome[i][i] = true;
                else if (i + 1 == j)
                    isPalindrome[i][j] = (s[i] == s[j]);
                else
                    isPalindrome[i][j] =
                        (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
            }
        }

        memset(t, -1, sizeof(t));
        t[n] = 0;

        // tabulation

        for (int i = n - 1; i >= 0; i--)
        {
            int ans = INT_MAX;
            for (int k = i; k < n; k++)
            {
                if (isPalindrome[i][k])
                {
                    ans = min(ans, t[k + 1]);
                }
            }

            t[i] = ans + 1;
        }

        return t[0] - 1;
    }
};

// time complexity: O(n^2)
// space complexity: O(n^2) + O(n)