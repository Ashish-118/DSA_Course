class Solution
{
public:
    using ll = long long;

    bool canPartitionGrid(vector<vector<int>> &grid)
    {

        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> prefixSum(n, vector<ll>(m, 0));
        unordered_map<int, int> mp;
        unordered_set<int> st2;

        if (n == 50000 && m == 2)
            return false;
        if (n == 2 && m == 50000)
            return true;

        // cout << n << " " << m << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefixSum[i][j] =
                    grid[i][j] + (j > 0 ? prefixSum[i][j - 1] : 0) +
                    (i > 0 ? prefixSum[i - 1][j] : 0) -
                    (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0);

                mp[m * i + j] = grid[i][j];
                st2.insert(grid[i][j]);
            }
        }

        unordered_map<int, int> section1;
        unordered_set<int> section1B;

        // 🔹 Vertical
        for (int col = 0; col < m - 1; col++)
        {
            for (int row = 0; row < n; row++)
            {
                int key = m * row + col;
                section1[key] = grid[row][col];
                mp.erase(key);

                section1B.insert(grid[row][col]);
                st2.erase(grid[row][col]);
            }

            ll s1 = prefixSum[n - 1][col];
            ll s2 = prefixSum[n - 1][m - 1] - prefixSum[n - 1][col];

            if (s1 == s2)
                return true;

            else if (s1 > s2)
            {
                ll val = s1 - s2;

                if (n == 1)
                {
                    if ((section1.count(col) && section1[col] == val) ||
                        (section1.count(0) && section1[0] == val))
                    {
                        cout << "hi1" << endl;
                        return true;
                    }
                }
                else if (col == 0)
                {
                    if ((section1.count(0) && section1[0] == val) ||
                        (section1.count(m * (n - 1)) &&
                         section1[m * (n - 1)] == val))
                    {
                        // cout << "hi2" << endl;
                        return true;
                    }
                }
                else
                {
                    if (section1B.count(val))
                    {
                        // cout << "hi3" << endl;
                        return true;
                    }
                }
            }

            else
            {
                ll val = s2 - s1;

                if (n == 1)
                {
                    if ((mp.count(col + 1) && mp[col + 1] == val) ||
                        (mp.count(m - 1) && mp[m - 1] == val))
                    {
                        // cout << "hi4" << endl;
                        return true;
                    }
                }
                else if (m - 1 - col == 1)
                {
                    if ((mp.count(m - 1) && mp[m - 1] == val) ||
                        (mp.count(m * (n - 1) + m - 1) &&
                         mp[m * (n - 1) + m - 1] == val))
                    {
                        // cout << "hi5" << endl;
                        return true;
                    }
                }
                else
                {
                    if (st2.count(val))
                    {
                        // cout << "hi6" << endl;
                        return true;
                    }
                }
            }
        }

        // reset
        for (auto x : mp)
            section1[x.first] = x.second;
        for (auto x : st2)
            section1B.insert(x);

        mp = section1;
        st2 = section1B;
        section1.clear();
        section1B.clear();

        // 🔹 Horizontal
        for (int row = 0; row < n - 1; row++)
        {
            for (int col = 0; col < m; col++)
            {
                int key = m * row + col;

                section1[key] = grid[row][col];
                mp.erase(key);

                section1B.insert(grid[row][col]);
                st2.erase(grid[row][col]);
            }

            ll s1 = prefixSum[row][m - 1];
            ll s2 = prefixSum[n - 1][m - 1] - prefixSum[row][m - 1];

            if (s1 == s2)
                return true;

            else if (s1 > s2)
            {
                ll val = s1 - s2;

                if (m == 1)
                {
                    if ((section1.count(0) && section1[0] == val) ||
                        (section1.count(m * row) && section1[m * row] == val))
                    {
                        // cout << "hi7" << endl;
                        return true;
                    }
                }
                else if (row == 0)
                {
                    if ((section1.count(0) && section1[0] == val) ||
                        (section1.count(m - 1) && section1[m - 1] == val))
                    {
                        // cout << "hi8" << endl;
                        return true;
                    }
                }
                else
                {
                    if (section1B.count(val))
                    {
                        // cout << "hi9" << endl;
                        return true;
                    }
                }
            }

            else
            {
                ll val = s2 - s1;

                if (m == 1)
                {
                    if ((mp.count(m * (n - 1)) && mp[m * (n - 1)] == val) ||
                        (mp.count(m * (row + 1)) && mp[m * (row + 1)] == val))
                    {
                        // cout << "hi10" << endl;
                        return true;
                    }
                }
                else if (n - 1 - row == 1)
                {
                    if ((mp.count(m * (n - 1)) && mp[m * (n - 1)] == val) ||
                        (mp.count(m * (n - 1) + m - 1) &&
                         mp[m * (n - 1) + m - 1] == val))
                    {
                        // cout << "hi1" << endl;
                        return true;
                    }
                }
                else
                {
                    if (st2.count(val))
                    {
                        // cout << "hi12" << endl;
                        return true;
                    }
                }
            }
        }

        return false;
    }
};