class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {

        int sumOdd = 0, sumEven = 0;
        for (int i = 1; i <= n; i++)
        {
            sumOdd += (2 * i - 1);
            sumEven += (2 * i);
        }

        return gcd(sumOdd, sumEven);
    }
};