class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int lastVal = -200;
        int toInsert = -1;
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (lastVal != nums[i])
            {
                lastVal = nums[i];
                toInsert++;
                nums[toInsert] = lastVal;
                k++;
            }
        }
        return k;
    }
};