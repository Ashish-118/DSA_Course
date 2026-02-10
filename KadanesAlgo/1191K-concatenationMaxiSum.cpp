class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        /* get array sum */
        long long array_sum = accumulate(arr.begin(), arr.end(), 0);

        if (k == 1)
        {

            long long max_subarray_sum = 0, tmp_sum = 0;

            // calculate max_subarray_sum  (KADANE'S ALGO)
            for (int i = 0; i < arr.size(); i++)
            {
                tmp_sum = max(tmp_sum + (long long)arr[i], (long long)arr[i]);
                max_subarray_sum = max(max_subarray_sum, tmp_sum);
            }

            return max_subarray_sum;
        }

        /* generate two times arr */
        vector<int> arr_cascade = arr;        // copy once
        arr_cascade.insert(arr_cascade.end(), // append
                           arr.begin(), arr.end());

        long long max_subarray_sum = 0, tmp_sum = 0;

        // calculate max_subarray_sum  (KADANE'S ALGO)
        for (int i = 0; i < arr_cascade.size(); i++)
        {
            tmp_sum = max(tmp_sum + (long long)arr_cascade[i],
                          (long long)arr_cascade[i]);
            max_subarray_sum = max(max_subarray_sum, tmp_sum);
        }
        return (max_subarray_sum + (array_sum > 0 ? array_sum * (k - 2) : 0)) %
               1000000007;
    }
};