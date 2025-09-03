class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int countZero = 0;
        int n = nums.size();

        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[index] = nums[i];
                index++;
            }
            else
            {
                countZero++;
            }
        }
        for (int i = 0; i < countZero; i++)
        {
            nums[index] = 0;
            index++;
        }
    }
};