class Solution
{
private:
    static inline int digisum(long long x)
    {
        int sum = 0;
        while (x)
        {
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }

public:
    long long makeIntegerBeautiful(long long n, int target)
    {
        long long original = n, base = 1;
        while (digisum(n) > target)
        {
            n = n / 10 + 1;
            base *= 10;
        }
        return n * base - original;
    }
};