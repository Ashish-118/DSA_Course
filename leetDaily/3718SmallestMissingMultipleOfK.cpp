class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        int mul = 1;

        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size(); i++)
        {
            if (mul * k == nums[i])
            {
                mul++;
            }
        }

        return mul * k;
    }
};


// -- java code

class Solution
{
public
    int missingMultiple(int[] nums, int k)
    {
        int n = nums.length;

        int mul = 1;

        Arrays.sort(nums);

        for (int i = 0; i < n; i++)
        {
            if (mul * k == nums[i])
            {
                mul++;
            }
        }

        return mul * k;
    }
}