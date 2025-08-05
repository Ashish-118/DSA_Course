class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        // Code Here
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        // find pivot and return it that's it
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] > arr[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
