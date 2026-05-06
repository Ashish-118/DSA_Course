class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for (int i = 0; i < n; i++)
        {
            int pointer = -1;
            for (int j = m - 1; j >= 0; j--)
            {

                if (boxGrid[i][j] == '.')
                {
                    pointer = max(pointer, j);
                }
                else if (boxGrid[i][j] == '*')
                {
                    pointer = -1;
                }
                else
                {
                    if (pointer == -1)
                        continue;
                    boxGrid[i][pointer] = '#';
                    boxGrid[i][j] = '.';
                    pointer--;
                }
            }
        }

        vector<vector<char>> ans(m, vector<char>(n, '.'));

        for (int j = 0; j < m; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                ans[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
};