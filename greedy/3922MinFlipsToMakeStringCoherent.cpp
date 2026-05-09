class Solution
{
public:
    int minFlips(string s)
    {
        int m1 = 0, m2 = 0, m3 = 0;

        int ones = 0, zeroes = 0;
        for (auto c : s)
        {
            if (c == '1')
                ones++;
            else
                zeroes++;
        }

        if (ones != 0)
        {
            m1 = ones - 1;
        }
        if (zeroes != 0)
        {
            m2 = zeroes;
        }

        if (s[0] == '0')
        {
            m3++;
        }

        if (s.back() == '0')
        {
            m3++;
        }

        for (int i = 1; i < s.length() - 1; i++)
        {
            if (s[i] == '1')
                m3++;
        }

        return min({m1, m2, m3});
    }
};