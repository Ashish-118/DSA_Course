class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        vector<int> ans;

        int top = -1;
        int count = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (top == nums[i])
            {
                count++;
            }
            else
            {
                count = 1;
                top = nums[i];
            }

            if (count == 2)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};