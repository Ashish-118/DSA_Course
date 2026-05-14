class Solution
{
public:
    bool isGood(vector<int> &nums)
    {
        vector<int> f(201, 0);
        int maxi = *max_element(begin(nums), end(nums));

        for (auto x : nums)
            f[x]++;

        for (int i = 1; i < maxi - 1; i++)
        {
            if (f[i] != 1)
                return false;
        }

        if (f[maxi] != 2)
            return false;

        return true;
    }
};