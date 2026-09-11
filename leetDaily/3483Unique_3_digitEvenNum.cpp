class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        unordered_map<int, int> f;

        for (auto d : digits)
        {
            f[d]++;
        }

        int ans = 0;

        for (auto m : f)
        {

            if (m.first & 1)
                continue;

            f[m.first]--;
            int unique = 0;
            int f_greater_than_2 = 0;

            for (auto x : f)
            {
                if (x.second)
                    unique++;

                if (x.second > 1 && x.first != 0)
                {
                    f_greater_than_2++;
                }
            }

            if (unique == 1 && f[0] == 0)
            {
                ans++;
            }
            else
            {
                int minus = (f[0] ? 1 : 0);
                int x = (unique - minus);

                ans += x * (x + minus - 1);
                ans += f_greater_than_2;
            }

            f[m.first]++;
        }

        return ans;
    }
};