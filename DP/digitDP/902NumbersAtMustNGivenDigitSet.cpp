class Solution
{
public:
    unordered_map<int, bool> mp;

    int t[10][2][2];

    int solve(int i, int tight, int leadingZeroes, string num)
    {
        if (i >= num.length())
        {
            if (!leadingZeroes)
            {
                return 1;
            }

            return 0;
        }

        if (t[i][tight][leadingZeroes] != -1)
            return t[i][tight][leadingZeroes];

        int l = (leadingZeroes ? 0 : 1);
        int r = (tight ? num[i] - '0' : 9);

        int ans = 0;

        for (int d = l; d <= r; d++)
        {
            if (mp.count(d))
            {
                ans += solve(i + 1, tight && (r == d),
                             leadingZeroes && (l == d), num);
            }
        }

        return t[i][tight][leadingZeroes] = ans;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        for (auto x : digits)
        {
            mp[x[0] - '0'] = true;
        }
        mp[0] = true;
        memset(t, -1, sizeof(t));

        string num = to_string(n);

        return solve(0, true, true, num);
    }
};