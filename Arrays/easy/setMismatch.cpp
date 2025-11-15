class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        int actualSum = 0;
        int sum = 0;
        int dup = 0;
        for (int i = 0; i < n; i++)
        {
            actualSum += (i + 1);
            sum += nums[i];
            freq[nums[i]]++;
            if (freq[nums[i]] > 1)
                dup = nums[i];
        }

        return {dup, dup + actualSum - sum};
    }
};