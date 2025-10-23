class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();

        vector<int> res(n, 0);
        int ans = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {

            res[i] += energy[i];
            if (i + k < n)
            {
                res[i] += res[i + k];
            }
            ans = max(ans, res[i]);
        }

        return ans;
    }
}; // time complexity O(n) and space complexity O(n)