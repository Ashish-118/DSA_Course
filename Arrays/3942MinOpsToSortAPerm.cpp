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


// approach -2

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {

        int n = nums.size();
        int idx = 0;

        bool check = true;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                check = false;
                break;
            }
        }

        if (check)
            return 0;

        check = true;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] < nums[i])
            {
                check = false;
                break;
            }
        }

        if (check)
            return 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                idx = i;
                break;
            }
        }

        bool rev = false;

        if (idx != n - 1 && abs(nums[idx] - nums[idx + 1]) != 1)
        {
            reverse(begin(nums), end(nums));
            rev = true;
        }

        if (rev)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                {
                    idx = i;
                    break;
                }
            }
        }

        int temp = 0;
        for (int i = idx; i < n; i++)
        {
            if (temp != nums[i])
            {
                return -1;
            }
            temp++;
        }

        for (int i = 0; i < idx; i++)
        {
            if (temp != nums[i])
            {
                return -1;
            }
            temp++;
        }

        int front = (rev ? 1 + n - idx : idx);
        int back = (rev ? 1 + idx : 2 + n - idx);

        return min(front, back);
    }
};