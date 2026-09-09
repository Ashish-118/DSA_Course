class Solution
{
public:
    long long countCommas(long long n)
    {
        long long ans = 0;

        long long temp1 = 1000;

        long long freq = 1;

        while (temp1 <= n)
        {
            long long temp2 = temp1 * 1000 - 1;

            long long mini = min(n, temp2);

            ans += freq * (mini - temp1 + 1);

            temp1 = temp2 + 1;
            freq++;
        }

        return ans;
    }
};