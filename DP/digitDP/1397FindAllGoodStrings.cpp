#define mod 1000000007
class Solution
{
public:
    int t[501][2][2][51];
    vector<int> LPS; // LPS

    int solve(int i, int tightLo, int tightHi, int j, string evil, string s1,
              string s2)
    {
        if (j >= evil.length())
        {
            return 0;
        }
        else if (i >= s1.length())
        {
            return 1;
        }

        if (t[i][tightLo][tightHi][j] != -1)
            return t[i][tightLo][tightHi][j];

        int lo = (tightLo ? s1[i] - 'a' : 0);
        int hi = (tightHi ? s2[i] - 'a' : 25);

        long long ans = 0;

        for (int d = lo; d <= hi; d++)
        {
            int x = j;

            while (x >= 0)
            { // KMP
                if (d == (evil[x] - 'a'))
                {
                    x++;
                    break;
                }
                else
                {
                    if (x != 0)
                    {
                        x = LPS[x - 1];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            ans = (ans + solve(i + 1, tightLo && (d == lo),
                               tightHi && (d == hi), x, evil, s1, s2)) %
                  mod;
        }

        return t[i][tightLo][tightHi][j] = ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil)
    {
        LPS.assign(n, 0);
        int len = evil.length();
        int j = 1;

        int maxLen = 0;

        while (j < len)
        {
            if (evil[maxLen] == evil[j])
            {
                maxLen++;
                LPS[j] = maxLen;
                j++;
            }
            else
            {
                if (maxLen == 0)
                {
                    LPS[j] = 0;
                    j++;
                }
                else
                {
                    maxLen = LPS[maxLen - 1];
                }
            }
        }

        memset(t, -1, sizeof(t));

        return solve(0, 1, 1, 0, evil, s1, s2);
    }
};