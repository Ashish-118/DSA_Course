class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int arraySum = accumulate(begin(nums), end(nums), 0);

        int expectedSum = ((n + 1) * (n)) / 2;
        cout << expectedSum << " " << arraySum;

        return expectedSum - arraySum;
    }
};