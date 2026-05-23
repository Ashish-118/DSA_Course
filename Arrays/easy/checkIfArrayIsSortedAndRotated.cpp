class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;

        // Check if the array is non-decreasing
        for (int i = 1; i < n; i++)
            if (nums[i - 1] > nums[i])
                count++;

        // Check if the last element is greater than the first element
        if (nums[n - 1] > nums[0])
            count++;

        // If the count of violations is less than or equal to 1, return true
        return count <= 1;
    }
};

// approach -2

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();

        int f1 = nums[0];
        int idx = n;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                idx = i;
                break;
            }
        }

        if (idx == n)
            return true;

        int l2 = nums[idx];
        int idx1 = n;
        for (int i = idx + 1; i < n; i++)
        {

            if (nums[i - 1] > nums[i])
            {
                idx1 = i;
                break;
            }
            l2 = nums[i];
        }

        if (idx1 != n || l2 > f1)
            return false;

        return true;
    }
};