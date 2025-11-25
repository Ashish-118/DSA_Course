class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        sort(begin(nums), end(nums));
        while (binary_search(nums.begin(), nums.end(), original))
        {

            original = 2 * original;
        }

        return original;
    }
};