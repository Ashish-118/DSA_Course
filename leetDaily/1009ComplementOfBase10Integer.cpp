class Solution
{
public:
    int bitwiseComplement(int n)
    {

        if (n == 0)
            return 1;
        int count = __builtin_popcount(n);
        int ans = 0;
        for (int i = 0; i < 32 && count; i++)
        {
            int bit = (n >> i) & 1;
            if (bit)
                count--;
            else
            {
                ans += pow(2, i);
            }
        }
        return ans;
    }
};