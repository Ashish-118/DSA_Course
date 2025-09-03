class Solution
{
public:
    int largest(vector<int> &arr)
    {

        return *max_element(begin(arr), end(arr));
    }
};
