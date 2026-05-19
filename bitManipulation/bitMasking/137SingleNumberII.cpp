class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            int zeroes = 0, ones = 0;

            for (auto x : nums)
            {
                if (x & (1 << i))
                {
                    ones++;
                }
                else
                {
                    zeroes++;
                }
            }

            if (ones % 3 != 0)
            {
                ans = ans | (1 << i);
            }
        }

        return ans;
    }
};