#define mod 1000000007
class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int n = corridor.size();
        int countSeats = 0;
        int mul = 0;
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
                countSeats++;

            if (countSeats == 2 && corridor[i] == 'S')
            {
                mul++;
            }
            else if (countSeats == 2 && corridor[i] == 'P')
            {
                mul++;
            }
            else if (countSeats > 2)
            {
                ans = (1LL * (ans % mod) * (mul % mod)) % mod;
                mul = 0;
                countSeats = 1;
            }
        }

        if (mul == 0)
            return 0;

        return ans;
    }
};