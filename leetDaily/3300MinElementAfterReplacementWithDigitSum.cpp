class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int x = nums[i];
            while (x != 0)
            {
                int d = x % 10;
                sum += d;
                x /= 10;
            }
            nums[i] = sum;
            ans = min(ans, sum);
        }

        return ans;
    }
};