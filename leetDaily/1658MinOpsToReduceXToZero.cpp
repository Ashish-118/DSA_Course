class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int suffix = 0;

        int ans = INT_MAX;

        for (int i = n - 1; i >= 0; i--)
        {

            if (suffix > x)
                break;

            int tar = x - suffix;

            int idx = lower_bound(prefix.begin(), prefix.begin() + i, tar) -
                      prefix.begin();
            int front = 0;

            if (idx >= n || (suffix != x && prefix[idx] != tar))
            {
                suffix += nums[i];
                continue;
            }

            if (suffix != x)
                front = idx + 1;

            int end = n - (i + 1);

            suffix += nums[i];

            ans = min(ans, front + end);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};