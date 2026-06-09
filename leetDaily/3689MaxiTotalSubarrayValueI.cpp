class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));

        return abs(mini - maxi) * 1LL * k;
    }
};