class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int ans = 0;
        for (int i = left; i <= right; i++)
        {

            int count = __builtin_popcount(i);
            bool check = true;

            for (int x = 2; x <= sqrt(count); x++)
            {
                if (count % x == 0)
                {
                    check = false;
                    break;
                }
            }

            if (count >= 2 && check)
                ans++;
        }

        return ans;
    }
};