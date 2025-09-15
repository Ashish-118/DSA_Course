// User function template for C++
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {

        int row = -1;
        int n = arr.size();
        int ones = -1;
        for (int i = 0; i < n; i++)
        {

            int lower = lower_bound(begin(arr[i]), end(arr[i]), 1) - arr[i].begin();
            int upper = upper_bound(begin(arr[i]), end(arr[i]), 1) - arr[i].begin();

            if ((upper - lower) != 0 && (upper - lower) > ones)
            {
                ones = abs(lower - upper);
                row = i;
            }
        }

        return row;
    }
}; // tc: O(nlogm) sc: O(1)