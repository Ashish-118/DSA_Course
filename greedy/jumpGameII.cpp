class Solution
{

public:
    int jump(vector<int> &nums)
    {
        int maxReach = nums[0];
        int nextMax = 0;
        int step = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                step++;
                break;
            }
            nextMax = max(nextMax, i + nums[i]);
            if (maxReach == i)
            {
                maxReach = nextMax;
                step++;
            }
        }
        return step;
    }
};