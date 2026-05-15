class Solution
{
    int pivot(vector<int> &arr, int s, int e)
    {

        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (arr[mid] > arr[e])
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

public:
    int findMin(vector<int> &nums)
    {

        int index = pivot(nums, 0, (nums.size() - 1));
        return nums[index];
    }
};