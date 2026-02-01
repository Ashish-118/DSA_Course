class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        // approach 1: O(nlogn)

        // sort(begin(nums) + 1, end(nums));
        // return accumulate(begin(nums), begin(nums) + 3, 0);

        //---------------

        // aproach 2: O(n)

        int num1 = INT_MAX, num2 = INT_MAX;

        for (int i = 1; i < nums.size(); i++)
        {
            if (num1 >= nums[i])
            {
                num2 = num1;
                num1 = nums[i];
            }
            else
            {
                num2 = min(num2, nums[i]);
            }
        }

        return nums[0] + num1 + num2;
    }
};