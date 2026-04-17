class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = 0;
        int carry = 0;

        for (int i = 0; i < 32; i++)
        {
            int bit_a = a & (1 << i);
            int bit_b = b & (1 << i);

            if (bit_a && bit_b)
            {
                if (carry)
                {
                    sum = sum | (1 << i);
                }
                carry = 1;
            }
            else if (bit_a || bit_b)
            {
                if (carry)
                {
                    carry = 1;
                }
                else
                {
                    sum = sum | (1 << i);
                }
            }
            else
            {
                if (carry)
                {
                    sum = sum | (1 << i);
                    carry = 0;
                }
            }
        }

        return sum;
    }
};