// this is the solution for the leetcode Daily problem -- partition array such that the max diff is k --2294

class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int i = 0;
        int check = 0;
        int ans = 0;

        while (i < nums.size())
        {
            if (abs(nums[check] - nums[i]) > k)
            {
                check = i;
                ans++;
            }
            i++;
        }
        return ans + 1;
    }
};