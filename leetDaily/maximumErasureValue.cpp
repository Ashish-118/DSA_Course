class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {

        int l = 0, r = -1;
        int n = nums.size();
        map<int, int> m;
        int ans = -1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;

            while (m[nums[i]] > 1)
            {
                m[nums[l]]--;
                sum -= nums[l];
                l++;
            }

            r = i;
            sum += nums[r];
            ans = max(ans, sum);
        }

        return ans;
    }
};