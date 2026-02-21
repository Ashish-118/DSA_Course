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

// another approach

int countPrimeSetBits(int left, int right)
{
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    int count = 0;

    for (int num = left; num <= right; num++)
    {
        if (primes.count(__builtin_popcount(num)))
        {
            count++;
        }
    }

    return count;
}