class Solution
{
public:
    int t[101][5001];
    int solve(int i, vector<int> &nums, int target, int sum)
    {

        if (i >= nums.size())
        {
            if (target == sum)
            {
                return 0;
            }

            return INT_MAX;
        }
        if (t[i][sum] != -1)
            return t[i][sum];
        int miniSteps = solve(i + 1, nums, target, sum);

        int temp = nums[i];
        int d = 0;

        while (temp)
        {
            int temp2 = temp >> d;
            if (temp2 <= 0)
                break;

            int m = 0;
            int steps = INT_MAX;

            while (sum + (temp2 << m) <= target)
            {

                int ret = solve(i + 1, nums, target, sum + (temp2 << m));
                if (ret != INT_MAX)
                {
                    steps = min(steps, d + m + ret);
                }
                m++;
            }

            miniSteps = min(steps, miniSteps);

            d++;
        }

        return t[i][sum] = miniSteps;
    }
    int minOperations(vector<int> &nums, int sum)
    {
        memset(t, -1, sizeof(t));
        int ret = solve(0, nums, sum, 0);
        return ret == INT_MAX ? -1 : ret;
    }
};