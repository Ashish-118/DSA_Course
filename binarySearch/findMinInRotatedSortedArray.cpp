class Solution
{
    int pivot(vector<int> &arr, int s, int e)
    {
        int mid = s + (e - s) / 2;

        if (arr[s] < arr[e] || e == 0)
        {
            return 0;
        }
        if (s == (e - 1))
        {
            return e;
        }

        if (arr[mid] >= arr[0])
        {
            return pivot(arr, mid, e);
        }
        else
        {

            return pivot(arr, s, mid);
        }
    }

public:
    int findMin(vector<int> &nums)
    {

        int index = pivot(nums, 0, (nums.size() - 1));
        return nums[index];
    }
};

// more easy pizzy

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
