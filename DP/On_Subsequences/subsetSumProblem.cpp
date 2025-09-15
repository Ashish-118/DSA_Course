class Solution
{
public:
    bool solve(int i, int sum, int tar, int n, vector<int> &arr)
    {
        if (sum == tar)
            return 1;
        if (i >= n || sum > tar)
            return 0;

        int take = solve(i + 1, sum + arr[i], tar, n, arr);
        if (take == 1)
            return 1;
        int notTake = solve(i + 1, sum, tar, n, arr);
        if (notTake == 1)
            return 1;

        return 0;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {

        int n = arr.size();
        return solve(0, 0, sum, n, arr);
    }
}; // reccursion approach