class Solution
{
public:
    bool poss(vector<int> &nums, int threshold, int div)
    {

        int sum = 0;
        for (auto &x : nums)
        {
            sum += (x % div == 0 ? x / div : x / div + 1);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int s = 1, e = 1e9;

        while (s < e)
        {
            int mid = s + (e - s) / 2;

            if (poss(nums, threshold, mid))
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};