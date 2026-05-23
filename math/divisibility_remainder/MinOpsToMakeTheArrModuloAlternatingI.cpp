class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = INT_MAX;
        for (int x = 0; x < k; x++)
        {

            for (int y = 0; y < k; y++)
            {
                if (x == y)
                    continue;

                int ops = 0;

                for (int idx = 0; idx < n; idx++)
                {
                    int rem = nums[idx] % k;
                    if (idx & 1)
                    {
                        if (rem < y)
                        {
                            ops += min(abs(y - rem), (k - y) + rem);
                        }
                        else if (rem > y)
                        {
                            ops += min(abs(y - rem), (k - rem) + y);
                        }
                    }
                    else
                    {
                        if (rem < x)
                        {
                            ops += min(abs(x - rem), (k - x) + rem);
                        }
                        else if (rem > x)
                        {
                            ops += min(abs(x - rem), (k - rem) + x);
                        }
                    }
                }
                ans = min(ans, ops);
            }
        }

        return ans;
    }
};