class Solution
{
public:
    bool poss(long long minTime, vector<int> &time, int totalTrips)
    {
        long long possTrips = 0;
        for (auto &x : time)
        {
            possTrips += (minTime / x);
        }

        return possTrips >= totalTrips;
    }

    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long left = 1;

        long long minBus = *min_element(time.begin(), time.end());
        long long right = minBus * 1LL * totalTrips;

        while (left < right)
        {
            long long mid = left + (right - left) / 2;

            if (poss(mid, time, totalTrips))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return right;
    }
};