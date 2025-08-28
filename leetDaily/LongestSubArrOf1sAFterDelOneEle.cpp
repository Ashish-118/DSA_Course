class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int maxLen = 0, len = 0, countZero = 0, len2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (len != 0 && nums[i] == 0)
            {
                countZero++;
            }

            if (nums[i] == 0)
            {
                if (len != 0 && countZero > 1)
                {
                    countZero = 1;

                    len = len2;
                    len2 = 0;
                }
            }
            else
            {
                len++;
                if (countZero == 1)
                    len2++;
                maxLen = max(maxLen, len);
            }
        }
        return (maxLen == nums.size() ? maxLen - 1 : maxLen);
    }
};