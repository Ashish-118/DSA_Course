class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int ans = 0;
        int n = colors.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                if (colors[i] != colors[j])
                {
                    ans = max(ans, abs(i - j));
                }
            }
        }

        return ans;
    }
};