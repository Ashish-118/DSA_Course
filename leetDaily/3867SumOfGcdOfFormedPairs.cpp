class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixGcd(n, 0);

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);

            prefixGcd[i] = gcd(maxi, nums[i]);
        }

        sort(begin(prefixGcd), end(prefixGcd));

        long long sum = 0;

        for (int i = 0; i < (n / 2); i++)
        {
            sum += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }

        return sum;
    }
};