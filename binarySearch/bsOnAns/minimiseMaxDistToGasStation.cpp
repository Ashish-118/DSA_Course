class Solution
{
public:
    bool poss(vector<int> &arr, int k, double mid)
    {
        int count = 0;

        for (int i = 1; i < arr.size(); i++)
        {
            int diff = arr[i] - arr[i - 1];
            if (diff > mid)
            {
                count += diff / mid;
            }
        }

        if (count > k)
            return false;
        return true;
    }
    double findSmallestMaxDist(vector<int> &stations, int k)
    {

        double s = 0;
        int n = stations.size();
        double e = stations[n - 1] - stations[0];
        double ans = 0;
        while (s < e)
        {
            double mid = s + (e - s) / 2;

            if (poss(stations, k, mid))
            {
                ans = mid;
                e = mid - 0.000001;
            }
            else
            {
                s = mid + 0.000001;
            }
        }

        return ans;
    }
};