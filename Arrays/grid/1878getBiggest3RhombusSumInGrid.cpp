class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        set<int> st;

        for (int k = 3; k <= n && k <= m; k += 2)
        {
            for (int row = 0; row < n; row++)
            {
                if (row + k - 1 >= n)
                    continue;
                for (int col = 0; col < m; col++)
                {
                    if (col + k - 1 >= m)
                        continue;

                    int r2 = row + k - 1;
                    int c2 = col + k - 1;

                    int r = row + k / 2 - 1;
                    int c = col + 1;
                    int sum1 = 0;
                    for (int i = 1; i < k / 2; i++)
                    {
                        if (col + k / 2 == c && row == r)
                            break;
                        sum1 += grid[r--][c++];
                    }

                    r++;
                    c++;
                    int sum2 = 0;
                    for (int i = 1; i < k / 2; i++)
                    {
                        if (c2 == c && row + k / 2 == r)
                            break;
                        sum2 += grid[r++][c++];
                    }

                    r++;
                    c--;
                    int sum3 = 0;
                    for (int i = 1; i < k / 2; i++)
                    {
                        if (col + k / 2 == c && r2 == r)
                            break;
                        sum3 += grid[r++][c--];
                    }

                    r--;
                    c--;
                    int sum4 = 0;
                    for (int i = 1; i < k / 2; i++)
                    {
                        if (col == c && row + k / 2 == r)
                            break;
                        sum4 += grid[r--][c--];
                    }

                    int total = sum1 + sum2 + sum3 + sum4 +
                                grid[row + k / 2][col] +
                                grid[row][col + k / 2] + grid[row + k / 2][c2] +
                                grid[r2][col + k / 2];

                    if (st.size() < 3)
                    {
                        st.insert(total);
                    }
                    else if (st.find(total) == st.end() &&
                             total > *st.begin())
                    {
                        st.erase(st.begin());
                        st.insert(total);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (st.size() < 3)
                {
                    st.insert(grid[i][j]);
                }
                else if (st.find(grid[i][j]) == st.end() &&
                         grid[i][j] > *st.begin())
                {
                    st.erase(st.begin());
                    st.insert(grid[i][j]);
                }
            }
        }

        vector<int> ans;
        int i = 0;

        for (auto x : st)
        {
            if (i == 3)
                break;
            ans.push_back(x);
            i++;
        }
        reverse(begin(ans), end(ans));

        return ans;
    }
};