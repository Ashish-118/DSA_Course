class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        for (int i = 0; i < n; i++)
        {
            prefix[i] = nums[i] * (i > 0 ? prefix[i - 1] : 1);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = nums[i] * ((i + 1 < n) ? suffix[i + 1] : 1);
        }

        vector<int> answer(n);

        for (int i = 0; i < n; i++)
        {
            answer[i] = (i > 0 ? prefix[i - 1] : 1) * (i + 1 < n ? suffix[i + 1] : 1);
        }

        return answer;
    }
};