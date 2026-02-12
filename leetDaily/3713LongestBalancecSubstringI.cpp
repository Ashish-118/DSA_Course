class Solution
{
public:
    int longestBalanced(string s)
    {

        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> f;
            for (int j = i; j < n; j++)
            {
                f[s[j]]++;

                int prev = -1;
                bool check = true;
                for (auto x : f)
                {
                    if (prev == -1 || prev == x.second)
                    {
                        prev = x.second;
                    }
                    else
                    {
                        check = false;
                        break;
                    }
                }

                if (check)
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};