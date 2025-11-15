class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> newNum(n);
        for (int i = 0; i < n; i++)
        {
            newNum[i] = {nums[i], i};
        }
        sort(begin(newNum), end(newNum));

        vector<int> ans(n, 0);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[newNum[i].first]++;

            ans[newNum[i].second] = i + 1 - freq[newNum[i].first];
        }

        return ans;
    }
};