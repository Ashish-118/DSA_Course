class Solution
{
public:
    int binaryGap(int n)
    {
        int ans = 0;
        int diff = -1;

        for (int i = 0; i < 31; i++)
        {
            if (diff == -1 && (n >> i) & 1)
                diff = i;

            else if ((n >> i) & 1)
            {
                ans = max(ans, abs(diff - i));
                diff = i;
            }
        }

        return ans;
    }
};