class Solution
{
public:
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        int ans = INT_MAX;
        int n = words.size();

        for (int i = 0; i < words.size(); i++)
        {
            if (target != words[i])
                continue;

            if (i <= startIndex)
            {
                ans =
                    min(ans, min(startIndex - i, (n - 1) - startIndex + i + 1));
            }
            else
            {
                ans = min(ans, min(i - startIndex, startIndex + n - i));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};