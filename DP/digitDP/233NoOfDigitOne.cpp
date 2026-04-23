class Solution
{
public:
    int t[10][2][10];
    int solve(int i, int tight, int count_1, string s)
    {
        if (i >= s.length())
            return count_1;
        if (t[i][tight][count_1] != -1)
            return t[i][tight][count_1];

        int res = 0;
        int lb = 0;
        int ub = (tight ? s[i] - '0' : 9);

        for (int d = lb; d <= ub; d++)
        {
            res += solve(i + 1, (tight && (ub == d)), count_1 + (d == 1), s);
        }

        return t[i][tight][count_1] = res;
    }
    int countDigitOne(int n)
    {
        memset(t, -1, sizeof(t));
        return solve(0, 1, 0, to_string(n));
    }
};