class Solution
{
public:
    bool canEatAll(vector<int> &piles, int h, int k)
    {
        int actualHours = 0;

        for (auto x : piles)
        {
            actualHours += (x % k == 0 ? x / k : (x / k + 1));
        }
        if (actualHours <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (canEatAll(piles, h, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};