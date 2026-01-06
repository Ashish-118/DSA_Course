class Solution
{
public:
    int findMaxVal(int n, vector<vector<int>> &restrictions, vector<int> &diff)
    {
        vector<long long> arr(n, LLONG_MAX);
        arr[0] = 0;

        for (auto &r : restrictions)
        {
            arr[r[0]] = min(arr[r[0]], (long long)r[1]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] != LLONG_MAX)
            {
                arr[i + 1] = min(arr[i + 1], arr[i] + diff[i]);
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i + 1] != LLONG_MAX)
            {
                arr[i] = min(arr[i], arr[i + 1] + diff[i]);
            }
        }

        long long ans = 0;
        for (long long v : arr)
        {
            ans = max(ans, v);
        }
        return (int)ans;
    }
};