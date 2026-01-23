class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {

        auto check = [&]()
        {
            int n = nums.size();

            for (int i = 1; i < n; i++)
            {

                if (nums[i] < nums[i - 1])
                    return false;
            }
            return true;
        };

        int count = 0;

        while (!check())
        {
            count++;
            int min = INT_MAX;
            int idx = -1;

            vector<int> v;
            int l = nums.size();

            for (int i = 0; i < l - 1; i++)
            {
                if (min > nums[i] + nums[i + 1])
                {
                    min = nums[i] + nums[i + 1];
                    idx = i;
                }
            }

            for (int i = 0; i < l; i++)
            {
                if (i == idx)
                {
                    v.push_back(min);
                    i++;
                    continue;
                }

                v.push_back(nums[i]);
            }

            nums = v;
        }

        return count;
    }
};