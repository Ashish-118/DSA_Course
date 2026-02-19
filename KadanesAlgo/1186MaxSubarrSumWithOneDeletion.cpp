class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int no_power_used = arr[0];
        int power_used = 0;
        int n = arr.size();
        int res = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            int v1 = arr[i];
            int v2 = no_power_used + arr[i];
            int v3 = power_used + arr[i];
            int v4 = no_power_used;

            res = max(res, max(max(v1, v2), max(v3, v4)));

            no_power_used = max(v1, v2);
            power_used = max(v3, v4);
        }

        return res == INT_MIN ? arr[0] : res;
    }
};