class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int inc = 0;

        int n = nums.size();
        int len = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                len++;
            }
            else
            {
                inc = max(inc, len);
                len = 1;
            }
        }

        inc = max(inc, len);

        int dec = 0;
        len = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                len++;
            }
            else
            {
                dec = max(dec, len);
                len = 1;
            }
        }

        dec = max(dec, len);

        return max(inc, dec);
    }
};