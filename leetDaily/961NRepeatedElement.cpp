class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {

        unordered_map<int, int> freq;
        for (auto n : nums)
        {
            freq[n]++;
            if (freq[n] > 1)
                return n;
        }

        return -1;
    }
};