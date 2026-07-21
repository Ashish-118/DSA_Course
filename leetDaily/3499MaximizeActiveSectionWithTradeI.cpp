class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        s = "1" + s + "1";

        int prevZeroes = 0;
        int currentZeroes = 0;
        int ones = 0;
        int maxi = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (prevZeroes && currentZeroes && s[i] == '1')
            {
                maxi = max(maxi, prevZeroes + currentZeroes);
                prevZeroes = currentZeroes;

                currentZeroes = 0;

                ones = 1;
            }
            else if (prevZeroes && s[i] == '1')
            {
                ones++;
            }

            if (ones == 0 && s[i] == '0')
            {
                prevZeroes++;
                continue;
            }
            if (ones && s[i] == '0')
            {
                currentZeroes++;
                continue;
            }
        }

        ones = 0;

        for (auto x : s)
            if (x == '1')
                ones++;

        return ones + maxi - 2;
    }
};