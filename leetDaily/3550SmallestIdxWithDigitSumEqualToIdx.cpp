class Solution
{
public:
    int smallestIndex(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            string num = to_string(nums[i]);
            int sum = 0;
            for (auto d : num)
            {
                sum += d - '0';
            }

            if (sum == i)
                return i;
        }

        return -1;
    }
};