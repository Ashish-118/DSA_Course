class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> result;
        int n = grid.size(), m = grid[0].size();

        for (int row = 0; row < n; row++)
        {
            if (row + k - 1 >= n)
                continue;
            vector<int> ans;
            for (int col = 0; col < m; col++)
            {
                if (col + k - 1 >= m)
                    continue;
                int row2 = row + k - 1;
                int col2 = col + k - 1;

                set<int> st;

                for (int i = row; i <= row2; i++)
                {
                    for (int j = col; j <= col2; j++)
                    {
                        st.insert(grid[i][j]);
                    }
                }

                if (st.size() == 1)
                    ans.push_back(0);
                else
                {
                    int diff = INT_MAX;
                    int prev = INT_MIN;
                    for (auto x : st)
                    {
                        if (prev != INT_MIN)
                            diff = min(diff, abs(prev - x));
                        prev = x;
                    }
                    ans.push_back(diff);
                }
            }
            result.push_back(ans);
        }

        return result;
    }
};

// using sliding window
// - Time complexity:approximately O(n * m * k ^ 2)
//  - Space complexity:O(k ^ 2)

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> result;
        int n = grid.size(), m = grid[0].size();

        for (int row = 0; row < n; row++)
        {
            if (row + k - 1 >= n)
                continue;

            map<int, int> mp;
            for (int i = row; i <= row + k - 1; i++)
            {
                for (int j = 0; j <= k - 1; j++)
                {
                    mp[grid[i][j]]++;
                }
            }
            vector<int> ans;
            for (int col = 0; col < m; col++)
            {
                if (col + k - 1 >= m)
                    continue;
                int row2 = row + k - 1;
                int col2 = col + k - 1;

                if (col != 0)
                {
                    for (int i = row; i <= row2; i++)
                    {
                        mp[grid[i][col - 1]]--;
                        if (mp[grid[i][col - 1]] == 0)
                        {
                            mp.erase(grid[i][col - 1]);
                        }
                    }
                    for (int i = row; i <= row2; i++)
                    {
                        mp[grid[i][col2]]++;
                    }
                }

                if (mp.size() == 1)
                    ans.push_back(0);
                else
                {
                    int diff = INT_MAX;
                    int prev = INT_MIN;
                    for (auto x : mp)
                    {
                        if (prev != INT_MIN)
                            diff = min(diff, abs(prev - x.first));
                        prev = x.first;
                    }
                    ans.push_back(diff);
                }
            }
            result.push_back(ans);
        }

        return result;
    }
};

/// codeStoryWithMik solution

// Approach - Iterate and check all k*k matrices
// T.C : O(O((m−k)×(n−k)×k^2×logk)
// S.C : O(k^2)
class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++)
        {
            for (int j = 0; j <= n - k; j++)
            {

                // Set for distinct + sorted
                set<int> vals;

                for (int r = i; r <= i + k - 1; r++)
                {
                    for (int c = j; c <= j + k - 1; c++)
                    {
                        vals.insert(grid[r][c]);
                    }
                }

                // If all elements were same, set has only 1 element
                if (vals.size() == 1)
                {
                    continue;
                }

                int minAbsDiff = INT_MAX;
                auto prev = vals.begin();
                auto curr = next(prev);

                while (curr != vals.end())
                {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }

                result[i][j] = minAbsDiff;
            }
        }

        return result;
    }
};