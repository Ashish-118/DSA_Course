class Solution
{
public:
    vector<int> visited;
    int solve(int i, int tight, int leadingZero, string s)
    {
        if (i >= s.length())
            return 1;

        int res = 0;
        int lb = 0, ub = (tight ? s[i] - '0' : 9);

        for (int d = lb; d <= ub; d++)
        {
            if (!visited[d])
            {
                if (d != 0 || !leadingZero)
                {
                    leadingZero = false;
                    visited[d] = true;
                }
                res += solve(i + 1, tight && (d == ub), leadingZero, s);

                leadingZero = true;
                visited[d] = false;
            }
        }

        return res;
    }
    int countNumbersWithUniqueDigits(int n)
    {
        int ub = pow(10, n) - 1;
        visited.assign(10, false);

        return solve(0, 1, 1, to_string(ub));
    }
};