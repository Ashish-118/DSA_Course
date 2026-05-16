class Solution
{
public:
    int pivot(vector<int> &nums, int s, int e)
    {

        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if ((nums[mid] > nums[e]) ||
                (nums[mid] == nums[e] &&
                 nums[mid] == nums[pivot(nums, s, mid)]))
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }

        return s;
    }
    int findMin(vector<int> &nums)
    {
        int index = pivot(nums, 0, (nums.size() - 1));
        return nums[index];
    }
};