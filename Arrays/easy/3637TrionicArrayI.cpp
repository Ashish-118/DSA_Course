class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int p = 0, q = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                p = i;
            }
            else
            {
                break;
            }
        }

        for (int i = p + 1; i < n - 1; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                q = i;
            }
            else
            {
                break;
            }
        }

        for (int i = q + 1; i < n; i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                return false;
            }
        }

        return 0 < p && p < q && q < n - 1;
    }
};