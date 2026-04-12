class Solution
{
public:
    unordered_map<int, pair<int, int>> mp;
    vector<vector<vector<int>>> dp;
    int solve(int i, int f1, int f2, string word)
    {
        if (i >= word.size())
            return 0;

        if (dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        int finger1 = INT_MAX;
        int finger2 = INT_MAX;
        auto p2 = mp[word[i] - 'A'];

        if (f1 != 26)
        {
            auto p1 = mp[f1];

            finger1 = abs(p1.first - p2.first) + abs(p1.second - p2.second);
            finger1 += solve(i + 1, word[i] - 'A', f2, word);
        }
        else
        {
            finger1 = solve(i + 1, word[i] - 'A', f2, word);
        }

        if (f2 != 26)
        {
            auto p1 = mp[f2];

            finger2 = abs(p1.first - p2.first) + abs(p1.second - p2.second);
            finger2 += solve(i + 1, f1, word[i] - 'A', word);
        }
        else
        {
            finger2 = solve(i + 1, f1, word[i] - 'A', word);
        }

        return dp[i][f1][f2] = min(finger1, finger2);
    }

    int minimumDistance(string word)
    {
        int len = word.size();

        int alpha = 0;

        for (int i = 0; i < 5; i++)
        {
            bool check = false;
            for (int j = 0; j < 6; j++)
            {
                if (alpha == 26)
                {
                    check = true;
                    break;
                }

                mp[alpha] = {i, j};

                alpha++;
            }
            if (check)
                break;
        }

        dp.assign(len, vector<vector<int>>(27, vector<int>(27, -1)));

        return solve(0, 26, 26, word);
    }
};