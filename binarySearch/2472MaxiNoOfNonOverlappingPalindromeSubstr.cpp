class Solution
{
public:
    vector<vector<int>> p;
    using pp = pair<int, int>;

    vector<pp> palindromes;

    vector<int> nextIdx;
    vector<int> dp;

    int m;

    int solve(int i)
    {

        if (i >= m)
        {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        int take = 1 + solve(nextIdx[i]);

        int skip = solve(i + 1);

        // cout<<" i "<<i<<" take "<<take<<" skip "<<skip<<endl;

        return dp[i] = max(skip, take);
    }
    int maxPalindromes(string s, int k)
    {
        int n = s.length();
        p.assign(n, vector<int>(n, 0));

        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;

                if (len == 1)
                {
                    p[i][j] = 1;
                }
                else if (len == 2)
                {
                    p[i][j] = (s[i] == s[j]);
                }
                else
                {
                    p[i][j] = (s[i] == s[j] && p[i + 1][j - 1]);
                }

                if (len >= k && p[i][j])
                {
                    palindromes.push_back({i + 1, j + 1});
                }
            }
        }

        sort(begin(palindromes), end(palindromes));

        auto findNext_cmp = [&](int r, pp &mid)
        { return mid.first > r; };

        m = palindromes.size();

        // for(auto x:palindromes){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // cout<<endl;

        nextIdx.resize(m);
        for (int i = 0; i < m; i++)
        {
            int r = palindromes[i].second;
            nextIdx[i] = upper_bound(begin(palindromes), end(palindromes), r,
                                     findNext_cmp) -
                         begin(palindromes);
            // cout<<" i "<<i<<" nxt_idx "<<nextIdx[i]<<endl;
        }
        // cout<<endl;

        dp.assign(m, -1);

        return solve(0);
    }
};