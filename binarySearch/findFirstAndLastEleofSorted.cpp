class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = lowerBound(nums, target);
        int right = upperBound(nums, target) - 1;

        // Check if target exists
        if (left <= right && left < n && nums[left] == target && nums[right] == target)
        {
            return {left, right};
        }

        return {-1, -1};
    }

    int lowerBound(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size();
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int upperBound(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size();
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
