class Solution
{
public:
    int t[2000][2000];

    bool solve(int i, int j, string s, int c)
    {
        if (c == 1 && i <= j)
        {
            return t[i][j];
        }
        else if (i > j)
            return false;

        for (int k = i; k <= j; k++)
        {
            if (t[i][k])
            {
                if (solve(k + 1, j, s, c - 1))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool checkPartitioning(string s)
    {
        int n = s.length();

        int count = 0;

        memset(t, 0, sizeof(t));

        for (int L = 1; L <= n; L++)
        {
            for (int i = 0; i + L - 1 < n; i++)
            {
                int j = i + L - 1;

                if (i == j)
                    t[i][i] = true;
                else if (i + 1 == j)
                    t[i][j] = (s[i] == s[j]);
                else
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);

                if (t[i][j])
                    count++;
            }
        }

        return solve(0, n - 1, s, 3);
    }
};