class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        int lower = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int upper = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

        if (lower == arr.size() || arr[lower] != target)
            return 0;

        return upper - lower;
    }
};
