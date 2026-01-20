class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++)
        {

            for (int k = 0; k < nums[i]; k++)
            {
                int v = k | (k + 1);

                if (v == nums[i])
                {
                    ans[i] = k;
                    break;
                }
            }
        }

        return ans;
    }
};

// most optimal

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++)
        {

            int p = -1;

            for (int shift = 0; shift < 32; shift++)
            {
                if (nums[i] & (1 << shift))
                {
                    p = shift;
                }
                else
                {
                    break;
                }
            }

            if (p != -1)
            {
                ans[i] = nums[i] - pow(2, p);
            }
        }

        return ans;
    }
};