class Solution
{
public:
    int t[101][5001];

    int solve(int i, vector<int> &nums, int sum, int target)
    {

        if (i >= nums.size())
        {
            if (sum == target)
            {
                return 0;
            }
            else
            {
                return INT_MAX;
            }
        }

        if (t[i][sum] != -1)
            return t[i][sum];

        int miniOps = solve(i + 1, nums, sum, target);

        bool allow = true;
        int p = 0;

        while (allow)
        {

            int temp = nums[i] * pow(2, p);
            if (temp >= target)
            {
                allow = false;
            }

            int d = 0;
            while (temp)
            {
                if ((sum + temp) <= target)
                {
                    int ret = solve(i + 1, nums, sum + temp, target);

                    if (ret != INT_MAX)
                    {
                        miniOps = min(miniOps, d + p + ret);
                    }
                }

                temp /= 2;

                d++;
            }

            p++;
        }

        return t[i][sum] = miniOps;
    }
    int minOperations(vector<int> &nums, int sum)
    {
        memset(t, -1, sizeof(t));
        int ans = solve(0, nums, 0, sum);
        return ans == INT_MAX ? -1 : ans;
    }
};