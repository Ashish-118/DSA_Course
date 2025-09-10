class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;

        bool sign = true;
        if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0))
            sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;
        while (n >= d)
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            quotient += 1LL << cnt;
            n -= d << cnt;
        }

        if (quotient > INT_MAX)
        {
            return sign ? INT_MAX : INT_MIN;
        }

        return sign ? (int)quotient : -(int)quotient;
    }
};
