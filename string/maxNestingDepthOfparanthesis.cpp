class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;

        int balance = 0;
        for (auto &x : s)
        {
            if (x == '(')
                balance++;
            if (x == ')')
                balance--;

            ans = max(ans, balance);
        }
        return ans;
    }
};