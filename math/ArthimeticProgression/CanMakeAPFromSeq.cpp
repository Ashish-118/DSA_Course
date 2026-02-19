class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(begin(arr), end(arr));

        int diff = arr[1] - arr[0];

        int n = arr.size();

        for (int i = 1; i < n - 1; i++)
        {
            if (diff != (arr[i + 1] - arr[i]))
                return false;
        }

        return true;
    }
};