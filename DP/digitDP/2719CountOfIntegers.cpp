#define mod 1000000007
class Solution
{
public:
    int t[24][208][2][2];
    int solve(int i, int tightLo, int tightHi, int sum, int &min_sum, int &max_sum, string lo, string hi)
    {
        if (i >= hi.length())
        {
            if (min_sum <= sum && sum <= max_sum)
            {
                return 1;
            }

            return 0;
        }

        if (t[i][sum][tightLo][tightHi] != -1)
            return t[i][sum][tightLo][tightHi];

        int l = (tightLo ? lo[i] - '0' : 0);
        int r = (tightHi ? hi[i] - '0' : 9);

        long long ans = 0;

        for (int d = l; d <= r; d++)
        {
            if (sum + d <= max_sum)
            {
                ans = (ans + solve(i + 1, tightLo && (l == d), tightHi && (r == d), sum + d, min_sum, max_sum, lo, hi)) % mod;
            }
        }

        return t[i][sum][tightLo][tightHi] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        int len2 = num2.length();
        int len1 = num1.length();

        string lo = string(len2 - len1, '0') + num1;

        memset(t, -1, sizeof(t));

        return solve(0, 1, 1, 0, min_sum, max_sum, lo, num2);
    }
};