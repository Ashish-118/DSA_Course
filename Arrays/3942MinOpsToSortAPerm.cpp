class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();

        bool checkINC = true;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                checkINC = false;
                break;
            }
        }
        if (checkINC)
            return 0;

        bool checkDEC = true;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                checkDEC = false;
                break;
            }
        }
        if (checkDEC)
            return 1;

        // increasing pattern

        int idx1 = -1;
        int len1 = 1, len2 = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                idx1 = i;
                break;
            }
            len1++;
        }

        int idx2 = -1;

        for (int i = idx1 + 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                idx2 = i;
                break;
            }
            len2++;
        }

        if (idx2 == -1 && nums[n - 1] < nums[0])
        {
            return min(len1, len2 + 2);
        }
        /// for decreasing pattern

        idx1 = -1;
        len1 = 1;
        len2 = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                idx1 = i;
                break;
            }
            len1++;
        }

        idx2 = -1;

        for (int i = idx1 + 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                idx2 = i;
                break;
            }
            len2++;
        }

        if (idx2 == -1 && nums[n - 1] > nums[0])
        {
            return min(len1 + 1, len2 + 1);
        }

        return -1;
    }
};