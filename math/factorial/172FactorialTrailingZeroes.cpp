class Solution
{
public:
    int trailingZeroes(int n)
    {
        int fives = 0, twos = 0;

        for (int i = 2; i <= n; i++)
        {
            int x = i;
            while (x % 2 == 0)
            {
                twos++;
                x /= 2;
            }

            x = i;
            while (x % 5 == 0)
            {
                fives++;
                x /= 5;
            }
        }

        return min(twos, fives);
    }
};

// optimal

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;

        for (int i = 5; i <= n; i *= 5)
        {
            res += n / i;
        }

        return res;
    }
};