class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        int len = 0;
        int maxi = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                len++;
            }
            else
            {
                len = 0;
            }

            maxi = max(maxi, len);
        }

        return maxi;
    }
};