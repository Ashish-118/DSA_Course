class Solution
{
public:
    int reverseBits(int n)
    {

        int reverse_num = 0;

        for (int i = 0; i < 32; i++)
        {
            if ((n >> i) & 1)
            {
                reverse_num += pow(2, 31 - i);
            }
        }

        return reverse_num;
    }
};