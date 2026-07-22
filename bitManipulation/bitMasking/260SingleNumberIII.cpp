class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int arr_xor = 0;

        for (auto x : nums)
            arr_xor ^= x;

        int mask = 1;

        for (int i = 0; i < 32; i++)
        {
            if (arr_xor & (mask))
            {
                break;
            }

            mask <<= 1;
        }

        int num1 = 0, num2 = 0;

        for (auto &x : nums)
        {
            if (x & mask)
            {
                num1 ^= x;
            }
            else
            {
                num2 ^= x;
            }
        }

        return {num1, num2};
    }
};