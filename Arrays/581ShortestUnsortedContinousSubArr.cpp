class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();

        int l = -1, r = -1;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (l == -1)
                {
                    l = i;
                    r = i + 1;
                }
                else
                {
                    r = i + 1;
                }
            }
        }

        if (l == -1 || r == -1)
            return 0;

        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = l; i <= r; i++)
        {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        for (int i = 0; i < l; i++)
        {
            if (mini < nums[i])
            {
                l = i;
                break;
            }
        }

        for (int i = r + 1; i < n; i++)
        {
            if (maxi > nums[i])
            {
                r = i;
            }
        }
        return r - l + 1;
    }
};