class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        return 1 << (32 - __builtin_clz(nums.size()));
    }
};