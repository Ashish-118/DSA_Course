class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int ans = -1;
        int s = 0, e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[s] <= target)
            {
                if (target < nums[mid] ||
                    nums[s] > nums[mid] && nums[mid] < nums[e])
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else if (nums[e] >= target)
            {
                if (target > nums[mid] ||
                    nums[s] <= nums[mid] && nums[mid] >= nums[e])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            else
                break;
        }

        return ans;
    }
};