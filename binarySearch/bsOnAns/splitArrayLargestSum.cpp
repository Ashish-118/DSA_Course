class Solution
{
public:
    int poss(vector<int> &nums, int maxSum)
    {
        int prev = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if ((prev + nums[i]) <= maxSum)
            {
                prev += nums[i];
            }
            else
            {
                count++;
                prev = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int s = *max_element(begin(nums), end(nums));
        int e = accumulate(begin(nums), end(nums), 0);
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int val = poss(nums, mid);
            if (val <= k)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};