// T.C : O(m*n * log(m+n)), log because we are using ordered_map
// S.C : O(m*n)

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;

        vector<int> result;

        // fill the map using [i+j]
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for (auto &it : mp)
        {
            if (flip)
            {
                // it.second ko reverse kardo
                reverse(it.second.begin(), it.second.end());
            }

            for (int &num : it.second)
            {
                result.push_back(num);
            }

            flip = !flip;
        }

        return result;
    }
};

// best approach
// T.C : O(m*n)

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        bool dir = 1; // dir = 1 means up
        vector<int> ans(m * n);
        int i = 0, r = 0, c = 0;
        while (r < m && c < n)
        {
            ans[i] = mat[r][c];
            i++;
            int newr, newc;
            if (dir == 1)
            {
                newr = r - 1;
                newc = c + 1;
            }
            else
            {
                newr = r + 1;
                newc = c - 1;
            }

            if (newr >= 0 && newr < m && newc >= 0 && newc < n)
            {
                r = newr;
                c = newc;
            }
            else
            {
                if (dir == 1)
                {
                    if (c < n - 1)
                        c++;
                    else
                        r++;
                }
                else
                {
                    if (r < m - 1)
                        r++;
                    else
                        c++;
                }
                dir = !dir;
            }
        }
        return ans;
    }
};