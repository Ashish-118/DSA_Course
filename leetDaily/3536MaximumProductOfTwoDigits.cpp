class Solution
{
public:
    int maxProduct(int n)
    {
        int num1 = -1, num2 = -1;

        while (n != 0)
        {
            int x = n % 10;
            if (num1 < x)
            {
                num2 = num1;
                num1 = x;
            }
            else if (num2 < x)
            {
                num2 = x;
            }

            n /= 10;
        }

        return num1 * num2;
    }
};