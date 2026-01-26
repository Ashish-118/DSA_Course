class Solution
{
public:
    int p[101][101];
    int t[101][101];

    int solve(int i, int j, string s, int k)
    {
        if (k == 1 && i <= j)
        {
            return p[i][j];
        }
        else if (k == 1 && i > j || i > j)
            return INT_MAX;

        if (t[i][k] != -1)
            return t[i][k];

        int ans = INT_MAX;

        for (int c = i; c <= j; c++)
        {
            int v = solve(c + 1, j, s, k - 1);
            if (v != INT_MAX)
                ans = min(ans, p[i][c] + v);
        }

        return t[i][k] = ans;
    }

    int palindromePartition(string s, int k)
    {
        int n = s.length();

        memset(p, 0, sizeof(p));
        memset(t, -1, sizeof(t));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int count = 0;
                int x = i, y = j;

                while (x < y)
                {
                    if (s[x] != s[y])
                    {
                        count++;
                    }

                    x++;
                    y--;
                }

                p[i][j] = count;
            }
        }

        return solve(0, n - 1, s, k);
    }
};