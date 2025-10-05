class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int full = numBottles;
        int empty = 0;

        int ans = 0;
        while (full != 0)
        {
            ans += full;

            empty += full;
            int count = 0;
            while (empty >= numExchange)
            {
                count++;
                empty -= numExchange;
                numExchange++;
            }
            full = count;
        }

        return ans;
    }
};