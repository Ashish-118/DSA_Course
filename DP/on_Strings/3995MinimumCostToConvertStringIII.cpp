class Solution
{
public:
    int t[5001];
    int solve(int i, string &source, string &target,
              vector<vector<string>> &rules, vector<int> &costs)
    {
        if (i >= source.length())
        {
            return 0;
        }

        if (t[i] != -1)
            return t[i];

        int cost = INT_MAX;

        if (source[i] == target[i])
        {
            cost = min(cost, solve(i + 1, source, target, rules, costs));
        }

        int n = target.length();

        for (int r = 0; r < rules.size(); r++)
        {
            string pattern = rules[r][0];
            string replacement = rules[r][1];
            int len = pattern.length();

            if (i + len - 1 >= n)
                continue;

            bool check = false;

            if (memcmp(replacement.c_str(), target.c_str() + i, len) == 0)
            {
                check = true;
            }

            if (!check)
                continue;

            int count_asterisk = 0;

            for (int j = 0; j < len; j++)
            {
                if (pattern[j] == '*')
                    count_asterisk++;
                if (source[j + i] != pattern[j] && pattern[j] != '*')
                {
                    check = false;
                }
            }

            if (!check)
                continue;

            int res = solve(i + len, source, target, rules, costs);

            if (res != INT_MAX)
            {
                cost = min(cost, res + costs[r] + count_asterisk);
            }
        }

        return t[i] = cost;
    }

    int minCost(string source, string target, vector<vector<string>> &rules,
                vector<int> &costs)
    {

        memset(t, -1, sizeof(t));

        int res = solve(0, source, target, rules, costs);

        return res != INT_MAX ? res : -1;
    }
};