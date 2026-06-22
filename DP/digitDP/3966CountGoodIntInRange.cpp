class Solution
{
public:
    long long t[16][2][2][10][2];
    long long solve(int i, string lo, string up, int k, int tightLo,
                    int tightUp, int n, int prev, int leadingZeroes)
    {
        if (i >= n)
        {
            return 1;
        }

        if (t[i][tightLo][tightUp][prev][leadingZeroes] != -1)
            return t[i][tightLo][tightUp][prev][leadingZeroes];

        int l = tightLo ? lo[i] - '0' : 0;
        int r = tightUp ? up[i] - '0' : 9;

        long long res = 0;

        for (int j = l; j <= r; j++)
        {
            if (leadingZeroes)
            {
                if (j == 0)
                {
                    res += solve(i + 1, lo, up, k, tightLo && (j == l),
                                 tightUp && (j == r), n, j, 1);
                }
                else
                {
                    res += solve(i + 1, lo, up, k, tightLo && (j == l),
                                 tightUp && (j == r), n, j, 0);
                }
            }
            else
            {
                if (abs(prev - j) <= k)
                {
                    res += solve(i + 1, lo, up, k, tightLo && (j == l),
                                 tightUp && (j == r), n, j, 0);
                }
            }
        }

        return t[i][tightLo][tightUp][prev][leadingZeroes] = res;
    }
    long long goodIntegers(long long l, long long r, int k)
    {
        memset(t, -1, sizeof(t));
        string lo = to_string(l), up = to_string(r);
        int n = up.length();
        string toAppend = "";

        for (int i = 0; i < n - lo.length(); i++)
        {
            toAppend += '0';
        }

        string newLo = toAppend + lo;
        cout << newLo << endl;
        cout << up << endl;

        return solve(0, newLo, up, k, 1, 1, n, 0, 1);
    }
};