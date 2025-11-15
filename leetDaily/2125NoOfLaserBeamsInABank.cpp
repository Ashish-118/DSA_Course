class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int top = -1;
        int ans = 0;

        for (auto &s : bank)
        {
            int ones = count(s.begin(), s.end(), '1');
            if (ones == 0)
                continue;
            if (top == -1)
                top = ones;
            else
            {
                ans += top * ones;
                top = ones;
            }
        }

        return ans;
    }
};