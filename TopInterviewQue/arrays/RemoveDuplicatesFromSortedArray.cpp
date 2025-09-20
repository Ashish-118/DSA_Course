class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        int j = 0;
        int n = nums.size();
        int prev = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (prev == nums[i])
            {
                count++;
            }
            else
            {
                prev = nums[i];
                count = 1;
            }

            if (count <= 2)
            {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};