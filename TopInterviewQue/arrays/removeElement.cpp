class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        int count = 0;
        while (i < j)
        {
            if (nums[i] != val)
            {
                i++;
            }
            else if (nums[j] == val)
            {
                j--;
            }

            if (nums[i] == val && nums[j] != val)
            {
                swap(nums[i], nums[j]);
            }
        }

        for (int x = n - 1; x >= 0; x--)
        {
            if (nums[x] != val)
                break;
            count++;
        }

        return n - count;
    }
};