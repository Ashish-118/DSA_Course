class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int prev = -1;

        if (n < 3)
            return false;

        for (int i = 0; i < n; i++)
        {
            if (prev != -1 && arr[prev] >= arr[i])
            {
                break;
            }

            prev = i;
        }

        if (prev == 0 || prev == n - 1)
            return false;

        for (int i = prev + 1; i < n; i++)
        {

            if (arr[prev] <= arr[i])
                return false;

            prev = i;
        }

        return true;
    }
};