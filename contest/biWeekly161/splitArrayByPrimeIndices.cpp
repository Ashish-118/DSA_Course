class Solution
{
public:
    long long splitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p < n; ++p)
        {
            if (isPrime[p])
            {

                for (int i = p * p; i <= n; i += p)
                {
                    isPrime[i] = false;
                }
            }
        }

        long long prime_index_sum = 0;
        long long other_sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPrime[i])
            {
                prime_index_sum += nums[i];
            }
            else
            {
                other_sum += nums[i];
            }
        }
        return abs(prime_index_sum - other_sum);
    }
};
©leetcode