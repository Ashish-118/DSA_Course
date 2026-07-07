class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        int x = 0;

        int p = 0;
        int sum = 0;
        while (n != 0)
        {
            int digit = n % 10;

            if (digit != 0)
            {
                x = digit * pow(10, p) + x;
                p++;
            }

            sum += digit;

            n /= 10;
        }

        return 1LL * sum * x;
    }
};