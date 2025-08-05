
class Solution
{
public:
    using ll = long long;
    bool poss(vector<int> &bloomDay, int m, int k, int day)
    {
        int adj = 0;
        int count = 0;
        for (auto &x : bloomDay)
        {
            if (x <= day)
            {
                adj++;
            }
            else
            {
                adj = 0;
            }

            if (adj == k)
            {
                count++;
                adj = 0;
            }
        }
        return count >= m;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int s = 1, e = maxi;

        if (ll(m) * k > (long long)bloomDay.size())
            return -1;
        while (s < e)
        {
            int mid = s + (e - s) / 2;

            if (poss(bloomDay, m, k, mid))
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
}; // time: O(nlog(maxi)), space: O(1)