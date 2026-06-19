class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int ans = 0;
        int alt = 0;

        for (auto x : gain)
        {
            alt += x;
            ans = max(alt, ans);
        }

        return ans;
    }
};