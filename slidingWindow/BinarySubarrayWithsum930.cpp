// Approach-2 (Using Sliding Window)
// This could be a very easy sliding window but the presence of 0 makes it a little tricky.
// Example : [0, 0, 0, 1, 1] -> Total subarrays having goal = 2 will be 4 - {0, 0, 0, 1, 1},  {0, 0, 1, 1}, {0, 1, 1}, {1, 1}
// So, simply find the count of zeros before the sum has reached goal i.e. 3 (Now, 1+1 = goal, so total subarrays = prefix_zeros + 1 = 3 + 1 = 4)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int prefix_zeros = 0;
        int window_sum = 0;
        int count = 0;

        int i = 0, j = 0;

        while (j < nums.size())
        {
            window_sum += nums[j];

            while (i < j && (nums[i] == 0 || window_sum > goal))
            {
                if (nums[i] == 1)
                {
                    prefix_zeros = 0;
                }
                else
                {
                    prefix_zeros += 1;
                }

                window_sum -= nums[i];
                i++;
            }

            if (window_sum == goal)
            {
                count += 1 + prefix_zeros;
            }
            j++;
        }

        return count;
    }
};