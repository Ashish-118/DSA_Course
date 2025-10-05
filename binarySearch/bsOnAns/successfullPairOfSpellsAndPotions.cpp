class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(begin(potions), end(potions));

        int n = spells.size(), m = potions.size();

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int spell = spells[i];
            int low = 0;
            int high = m - 1;
            int index = m;

            while (low <= high)
            {

                int mid = low + (high - low) / 2;

                long long val = 1LL * spell * potions[mid];

                if (val >= success)
                {
                    index = min(index, mid);
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            ans[i] = m - index;
        }

        return ans;
    }
};