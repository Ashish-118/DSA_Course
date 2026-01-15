class Solution
{
public:
    int smallestEvenMultiple(int n)
    {
        return 2 * n / gcd(2, n);
    }
};