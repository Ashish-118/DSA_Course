class Solution
{
public:
    bool poss(vector<int> &weights, int days, int capacity)
    {
        int req_day = 1;

        int sum = 0;
        for (auto &x : weights)
        {
            sum += x;
            if (sum > capacity)
            {
                req_day++;
                sum = x;
            }
        }

        return req_day <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int s = *max_element(weights.begin(), weights.end()), e = 1e9;

        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (poss(weights, days, mid))
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