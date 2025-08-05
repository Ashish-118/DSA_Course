class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[low] == nums[mid] && nums[high] == nums[mid])
            {
                low++;
                high--;
            }
            else if (nums[low] <= nums[mid])
            {

                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[high] >= target && target > nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

// another way is to find the pivot point and then do binary search on both halves

class Solution
{
public:
    bool binarySearch(vector<int> &nums, int target, int low, int high)
    {

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }

    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();

        int pivot = -1;
        int l = 0, r = n - 1;
        while (l < r)
        {
            while (l < r && nums[l] == nums[l + 1])
                l++;
            while (l < r && nums[r] == nums[r - 1])
                r--;
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        pivot = l;
        cout << pivot << endl;
        if (binarySearch(nums, target, 0, pivot - 1))
        {
            return true;
        }
        return binarySearch(nums, target, pivot, n - 1);
    }
};