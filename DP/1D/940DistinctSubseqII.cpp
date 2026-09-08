class Solution
{
public:
    int mod = 1000000007;

    vector<int> lastSeen;
    vector<int> prev;

    int t[2001];
    int solve(int n)
    {
        if (n == 0)
        {
            return 1; // empty string;
        }

        if (t[n] != -1)
            return t[n];

        long long count = 2 * solve(n - 1);
        long long dup = 0;

        if (prev[n] != -1)
        {
            dup = solve(prev[n] - 1);
        }

        return t[n] = (count - dup + mod) % mod;
    }
    int distinctSubseqII(string s)
    {
        int n = s.length();
        memset(t, -1, sizeof(t));

        prev.assign(n + 1, -1);
        lastSeen.assign(26, -1);

        for (int i = 1; i <= n; i++)
        {
            int idx = s[i - 1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + mod) % mod;
    }
};