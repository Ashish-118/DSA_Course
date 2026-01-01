class Solution
{
public:
    vector<int> cumSum;
    Solution(vector<int> &w)
    {
        int n = w.size();
        cumSum.push_back(w[0]);
        for (int i = 1; i < n; i++)
        {
            cumSum.push_back(cumSum.back() + w[i]);
        }
    }

    int pickIndex()
    {
        int randw = rand() % cumSum.back();

        return upper_bound(begin(cumSum), end(cumSum), randw) - cumSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */