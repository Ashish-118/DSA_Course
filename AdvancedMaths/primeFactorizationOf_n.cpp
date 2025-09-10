class Solution
{
public:
    int largestPrimeFactor(int n)
    {
        int *ans = new int[n];
        int idx = 0;

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                ans[idx++] = i;
                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }

        if (n != 1)
            ans[idx++] = n;

        int maxi = INT_MIN;
        for (int i = 0; i < idx; i++)
        {
            maxi = max(maxi, ans[i]);
        }
        return maxi;
    }
}; // time complexity: O(sqrt(n)*log(n))