class Solution
{
public:
    bool poss(int mid, double hour, vector<int> &dist)
    {
        double time = 0;
        for (int i = 0; i < dist.size(); i++)
        {
            if (i == dist.size() - 1)
                time += ((double)(dist[i]) / mid);
            else
            {
                time += ((dist[i]) / mid);
                if (dist[i] % mid != 0)
                {
                    time++;
                }
            }
        }

        return time <= hour;
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int n = dist.size();
        int l = 1, r = 1e9;
        int ans = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (poss(mid, hour, dist))
            {
                r = mid - 1;
                ans = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};