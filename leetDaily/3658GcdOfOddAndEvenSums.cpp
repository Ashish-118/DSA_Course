class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        return gcd((n + n * (n - 1)), (2 * n + n * (n - 1)));
    }
};