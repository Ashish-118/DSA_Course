class Solution
{
public:
    int t[10][2][2][1 << 10];

    int solve(int i, int tight, int leadingZero, string s, int visited)
    {
        if (i >= s.length())
            return 1;

        if (t[i][tight][leadingZero][visited] != -1)
            return t[i][tight][leadingZero][visited];

        int res = 0;
        int ub = tight ? s[i] - '0' : 9;

        for (int d = 0; d <= ub; d++)
        {

            int newLeading = leadingZero;
            int newVisited = visited;

            if (leadingZero && d == 0)
            {
                // still leading zeros
            }
            else
            {
                newLeading = 0;

                if (newVisited & (1 << d))
                    continue;

                newVisited |= (1 << d);
            }

            res += solve(i + 1,
                         tight && (d == ub),
                         newLeading,
                         s,
                         newVisited);
        }

        return t[i][tight][leadingZero][visited] = res;
    }

    int countSpecialNumbers(int n)
    {
        memset(t, -1, sizeof(t));
        return solve(0, 1, 1, to_string(n), 0) - 1;
    }
};